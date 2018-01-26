/*
 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */


#include <algorithm>

#include "atlas/library/Library.h"
#include "atlas/field/FieldSet.h"
#include "atlas/functionspace/NodeColumns.h"
#include "atlas/functionspace/Spectral.h"
#include "atlas/functionspace/StructuredColumns.h"
#include "atlas/grid/Distribution.h"
#include "atlas/grid/Partitioner.h"
#include "atlas/grid.h"
#include "atlas/grid/detail/partitioner/EqualRegionsPartitioner.h"
#include "atlas/grid/detail/partitioner/TransPartitioner.h"
#include "atlas/meshgenerator/StructuredMeshGenerator.h"
#include "atlas/mesh/Mesh.h"
#include "atlas/mesh/Nodes.h"
#include "atlas/output/Gmsh.h"
#include "atlas/parallel/mpi/mpi.h"
#include "atlas/trans/Trans.h"
#include "atlas/array/MakeView.h"
#include "transi/trans.h"

#include "tests/AtlasTestEnvironment.h"
#include "eckit/testing/Test.h"

using namespace eckit;
using namespace eckit::testing;
using atlas::grid::detail::partitioner::TransPartitioner;
using atlas::grid::detail::partitioner::EqualRegionsPartitioner;

namespace atlas {
namespace test {

//-----------------------------------------------------------------------------

struct AtlasTransEnvironment : public AtlasTestEnvironment {
       AtlasTransEnvironment(int argc, char * argv[]) : AtlasTestEnvironment(argc, argv) {
         if( parallel::mpi::comm().size() == 1 )
           trans_use_mpi(false);
         trans_init();
       }

      ~AtlasTransEnvironment() {
         trans_finalize();
       }
};

//-----------------------------------------------------------------------------

void read_rspecg(trans::Trans& trans, std::vector<double>& rspecg, std::vector<int>& nfrom, int &nfld )
{
  Log::info() << "read_rspecg ...\n";
  nfld = 2;
  if( parallel::mpi::comm().rank() == 0 )
  {
    rspecg.resize(nfld*trans.nb_spectral_coefficients_global());
    for( int i=0; i<trans.nb_spectral_coefficients_global(); ++i )
    {
      rspecg[i*nfld + 0] = (i==0 ? 1. : 0.); // scalar field 1
      rspecg[i*nfld + 1] = (i==0 ? 2. : 0.); // scalar field 2
    }
  }
  nfrom.resize(nfld);
  for (int jfld=0; jfld<nfld; ++jfld)
    nfrom[jfld] = 1;

  Log::info() << "read_rspecg ... done" << std::endl;
}

//-----------------------------------------------------------------------------

CASE( "test_trans_distribution_matches_atlas" )
{
  EXPECT( grid::Partitioner::exists("trans") );


  // Create grid and trans object
  Grid g( "N80" );

  EXPECT( grid::StructuredGrid(g).ny() == 160 );

  auto trans_partitioner = new TransPartitioner();
  grid::Partitioner partitioner( trans_partitioner );
  grid::Distribution distribution( g, partitioner );

  trans::Trans trans( g );
  ::Trans_t* t = trans;

  ATLAS_DEBUG_VAR( trans.truncation() );
  EXPECT( trans.truncation() <= 0 );

  // -------------- do checks -------------- //
  EXPECT( t->nproc  ==  parallel::mpi::comm().size() );
  EXPECT( t->myproc == parallel::mpi::comm().rank()+1 );


  if( parallel::mpi::comm().rank() == 0 ) // all tasks do the same, so only one needs to check
  {
    int max_nb_regions_EW(0);
    for( int j=0; j<trans_partitioner->nb_bands(); ++j )
      max_nb_regions_EW = std::max(max_nb_regions_EW, trans_partitioner->nb_regions(j));

    EXPECT( t->n_regions_NS == trans_partitioner->nb_bands() );
    EXPECT( t->n_regions_EW == max_nb_regions_EW );

    EXPECT( distribution.nb_partitions() == parallel::mpi::comm().size() );
    EXPECT( distribution.partition().size() == g.size() );

    std::vector<int> npts(distribution.nb_partitions(),0);

    for(size_t j = 0; j < g.size(); ++j)
      ++npts[distribution.partition(j)];

    EXPECT( trans.nb_gridpoints_global()  == g.size() );
    EXPECT( trans.nb_gridpoints() ==  npts[parallel::mpi::comm().rank()] );
    EXPECT( t->ngptotmx == *std::max_element(npts.begin(),npts.end()) );

    // array::LocalView<int,1> n_regions ( trans.n_regions() ) ;
    for( int j=0; j<trans_partitioner->nb_bands(); ++j )
      EXPECT( t->n_regions[j] == trans_partitioner->nb_regions(j) );
  }
}

CASE( "test_trans_partitioner" )
{
  Log::info() << "test_trans_partitioner" << std::endl;
  // Create grid and trans object
  Grid g( "N80" );

  trans::Trans trans( g );

  EXPECT( trans.truncation() <= 0 );
  EXPECT( trans.nb_gridpoints_global() == g.size() );
}

CASE( "test_trans_options" )
{
  trans::Trans::Options opts;
  opts.set_fft(trans::FFTW);
  opts.set_split_latitudes(false);
  opts.set_read("readfile");

  Log::info() << "trans_opts = " << opts << std::endl;
}

CASE( "test_distspec" )
{
  trans::Trans::Options p;

#ifdef TRANS_HAVE_IO
  if( parallel::mpi::comm().size() == 1 )
    p.set_write("cached_legendre_coeffs");
#endif
  p.set_flt(false);
  trans::Trans trans( Grid("F400"), 159, p);
  Log::info() << "Trans initialized" << std::endl;
  std::vector<double> rspecg;
  std::vector<int   > nfrom;
  int nfld;
  Log::info() << "Read rspecg" << std::endl;
  read_rspecg(trans,rspecg,nfrom,nfld);


  std::vector<double> rspec(nfld*trans.nb_spectral_coefficients());
  std::vector<int> nto(nfld,1);
  std::vector<double> rgp(nfld*trans.nb_gridpoints());
  std::vector<double> rgpg(nfld*trans.nb_gridpoints_global());
  std::vector<double> specnorms(nfld,0);

  trans.distspec( nfld, nfrom.data(), rspecg.data(), rspec.data() );
  trans.specnorm( nfld, rspec.data(), specnorms.data() );
  trans.invtrans( nfld, rspec.data(), rgp.data() );
  trans.gathgrid( nfld, nto.data(),   rgp.data(),    rgpg.data() );

  if( parallel::mpi::comm().rank() == 0 ) {
    EXPECT( eckit::types::is_approximately_equal( specnorms[0], 1., 1.e-10 ));
    EXPECT( eckit::types::is_approximately_equal( specnorms[1], 2., 1.e-10 ));
  }

  Log::info() << "end test_distspec" << std::endl;
}

CASE( "test_distspec_speconly" )
{
  trans::Trans::Options p;

  p.set_flt(false);
  trans::Trans trans( 159, p);
  Log::info() << "Trans initialized" << std::endl;
  std::vector<double> rspecg;
  std::vector<int   > nfrom;
  int nfld;
  Log::info() << "Read rspecg" << std::endl;
  read_rspecg(trans,rspecg,nfrom,nfld);


  std::vector<double> rspec(nfld*trans.nb_spectral_coefficients());
  std::vector<int> nto(nfld,1);
  std::vector<double> specnorms(nfld,0);

  trans.distspec( nfld, nfrom.data(), rspecg.data(), rspec.data() );
  trans.specnorm( nfld, rspec.data(), specnorms.data() );

  if( parallel::mpi::comm().rank() == 0 ) {
    EXPECT( eckit::types::is_approximately_equal( specnorms[0], 1., 1.e-10 ));
    EXPECT( eckit::types::is_approximately_equal( specnorms[1], 2., 1.e-10 ));
  }

  Log::info() << "end test_distspec_only" << std::endl;
}

CASE( "test_distribution" )
{
  Grid g( "O80" );

  Log::info() << "test_distribution" << std::endl;

  grid::Distribution d_trans = grid::Partitioner( new TransPartitioner() ).partition(g);
  Log::info() << "trans distribution created" << std::endl;


  grid::Distribution d_eqreg = grid::Partitioner( new EqualRegionsPartitioner() ).partition(g);
  Log::info() << "eqregions distribution created" << std::endl;

  if( parallel::mpi::comm().rank() == 0 )
  {
    EXPECT( d_trans.nb_partitions() == d_eqreg.nb_partitions() );
    EXPECT( d_trans.max_pts() == d_eqreg.max_pts() );
    EXPECT( d_trans.min_pts() == d_eqreg.min_pts() );

    EXPECT( d_trans.nb_pts() == d_eqreg.nb_pts() );
  }

}

CASE( "test_generate_mesh" )
{
  Log::info() << "test_generate_mesh" << std::endl;
  Grid g( "O80" );
  meshgenerator::StructuredMeshGenerator generate( atlas::util::Config
    ("angle",0)
    ("triangulate",true)
  );
  trans::Trans trans(g);

  Mesh m_default = generate( g );

  Log::info() << "trans_distribution" << std::endl;
  grid::Distribution trans_distribution = grid::Partitioner( new TransPartitioner() ).partition(g);
  Mesh m_trans = generate( g, trans_distribution );

  Log::info() << "eqreg_distribution" << std::endl;
  grid::Distribution eqreg_distribution = grid::Partitioner( new EqualRegionsPartitioner() ).partition(g);
  Mesh m_eqreg = generate( g, eqreg_distribution );

  array::ArrayView<int,1> p_default = array::make_view<int,1>( m_default.nodes().partition() );
  array::ArrayView<int,1> p_trans   = array::make_view<int,1>( m_trans  .nodes().partition() );
  array::ArrayView<int,1> p_eqreg   = array::make_view<int,1>( m_eqreg  .nodes().partition() );

  for( size_t j=0; j<p_default.shape(0); ++j ) {
    EXPECT( p_default(j) == p_trans(j) );
    EXPECT( p_default(j) == p_eqreg(j) );
  }

  output::Gmsh("N16_trans.msh").write(m_trans);
}


CASE( "test_spectral_fields" )
{
  Log::info() << "test_spectral_fields" << std::endl;

  Grid g( "O48" );
  meshgenerator::StructuredMeshGenerator generate( atlas::util::Config
    ("angle",0)
    ("triangulate",false)
  );
  Mesh m = generate( g );

  trans::Trans trans(g,47);


  functionspace::NodeColumns nodal (m);
  functionspace::Spectral spectral (trans);

  Field spf = spectral.createField<double>(option::name("spf"));
  Field gpf = nodal.   createField<double>(option::name("gpf"));


  EXPECT_NO_THROW( trans.dirtrans(nodal,gpf,spectral,spf) );
  EXPECT_NO_THROW( trans.invtrans(spectral,spf,nodal,gpf) );

  FieldSet gpfields;   gpfields.add(gpf);
  FieldSet spfields;   spfields.add(spf);

  EXPECT_NO_THROW( trans.dirtrans(nodal,gpfields,spectral,spfields) );
  EXPECT_NO_THROW( trans.invtrans(spectral,spfields,nodal,gpfields) );

  gpfields.add(gpf);
  EXPECT_THROWS_AS(trans.dirtrans(nodal,gpfields,spectral,spfields),eckit::SeriousBug);

}


CASE( "test_nomesh" )
{
  Log::info() << "test_spectral_fields" << std::endl;

  Grid g( "O48" );
  trans::Trans trans(g,47) ;

  functionspace::Spectral          spectral   (trans);
  functionspace::StructuredColumns gridpoints (g);

  Field spfg = spectral.  createField<double>(option::name("spf") | option::global());
  Field spf  = spectral.  createField<double>(option::name("spf"));
  Field gpf  = gridpoints.createField<double>(option::name("gpf"));
  Field gpfg = gridpoints.createField<double>(option::name("gpf") | option::global());

  array::ArrayView<double,1> spg = array::make_view<double,1>(spfg);
  if( parallel::mpi::comm().rank() == 0 ) {
    spg.assign(0.);
    spg(0) = 4.;
  }

  EXPECT_NO_THROW( spectral.scatter(spfg,spf) );

  if( parallel::mpi::comm().rank() == 0 ) {
    array::ArrayView<double,1> sp = array::make_view<double,1>(spf);
    EXPECT( eckit::types::is_approximately_equal( sp(0), 4., 0.001 ));
    for( size_t jp=0; jp<sp.size(); ++jp ) {
      Log::debug() << "sp("<< jp << ")   :   " << sp(jp) << std::endl;
    }
  }

  EXPECT_NO_THROW( trans.invtrans(spf,gpf) );

  EXPECT_NO_THROW( gridpoints.gather(gpf,gpfg) );

  if( parallel::mpi::comm().rank() == 0 ) {
    array::ArrayView<double,1> gpg = array::make_view<double,1>(gpfg);
    for( size_t jp=0; jp<gpg.size(); ++jp ) {
      EXPECT( eckit::types::is_approximately_equal( gpg(jp), 4., 0.001 ));
      Log::debug() << "gpg("<<jp << ")   :   " << gpg(jp) << std::endl;
    }
  }

  EXPECT_NO_THROW( gridpoints.scatter(gpfg,gpf) );

  EXPECT_NO_THROW( trans.dirtrans(gpf,spf) );

  EXPECT_NO_THROW( spectral.gather(spf,spfg) );

  if( parallel::mpi::comm().rank() == 0 ) {
    EXPECT( eckit::types::is_approximately_equal( spg(0), 4., 0.001 ));
  }
}

//-----------------------------------------------------------------------------

}  // namespace test
}  // namespace atlas


int main(int argc, char **argv) {
    atlas::test::AtlasTransEnvironment env( argc, argv );
    return run_tests ( argc, argv, false );
}