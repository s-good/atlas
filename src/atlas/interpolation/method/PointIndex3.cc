
/*
 * (C) Copyright 1996-2017 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

#include "atlas/interpolation/method/PointIndex3.h"

#include "atlas/array/ArrayView.h"
#include "atlas/array/MakeView.h"
#include "atlas/mesh/HybridElements.h"
#include "eckit/config/Resource.h"
#include "eckit/eckit_version.h"

#ifdef ECKIT_VERSION_INT
#undef ECKIT_VERSION_INT
#endif
#define ECKIT_VERSION_INT (ECKIT_MAJOR_VERSION * 10000 \
                         + ECKIT_MINOR_VERSION * 100 \
                         + ECKIT_PATCH_VERSION)

namespace atlas {
namespace interpolation {
namespace method {

ElemIndex3* create_element_kdtree(const Field& field_centres) {

    const array::ArrayView<double, 2> centres = array::make_view<double, 2>( field_centres );

    static bool fastBuildKDTrees = eckit::Resource<bool>("$ATLAS_FAST_BUILD_KDTREES", true);

    // If eckit version <= 0.17.0
#   if ECKIT_VERSION_INT <= 1700
    fastBuildKDTrees = true;
#   endif

    ElemIndex3* tree = new ElemIndex3();
    const size_t nb_cells = centres.shape(0);

    if (fastBuildKDTrees) {
        std::vector< ElemIndex3::Value > p;
        p.reserve(nb_cells);

        for (size_t j = 0; j < nb_cells; ++j) {
            p.push_back(ElemIndex3::Value(
                            ElemIndex3::Point(centres(j, XX), centres(j, YY), centres(j, ZZ)),
                            ElemIndex3::Payload(j) ));
        }

        tree->build(p.begin(), p.end());
    }

    // If eckit version > 0.17.0
#   if ECKIT_VERSION_INT > 1700
    else {
        for (size_t j = 0; j < nb_cells; ++j) {
            tree->insert(ElemIndex3::Value(
                             ElemIndex3::Point(centres(j, XX), centres(j, YY), centres(j, ZZ)),
                             ElemIndex3::Payload(j) ));
        }
    }
#   endif
    return tree;
}


ElemIndex3* create_element_centre_index(const Mesh& mesh) {
    return create_element_kdtree( mesh.cells().field("centre") );
}


} // namespace method
} // namespace interpolation
} // namespace atlas

