#ifndef atlas_regular_lat_lon_grid_H
#define atlas_regular_lat_lon_grid_H
/*
 * (C) Copyright 1996-2014 ECMWF.
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 * In applying this licence, ECMWF does not waive the privileges and immunities
 * granted to it by virtue of its status as an intergovernmental organisation nor
 * does it submit to any jurisdiction.
 */

#include <cstddef>
#include <vector>

#include "atlas/grid/Grid.h"

//-----------------------------------------------------------------------------

namespace atlas {
namespace grid {

//-----------------------------------------------------------------------------

class RegularLatLonGrid : public Grid {
public:
   RegularLatLonGrid();
   RegularLatLonGrid(  const std::string& hash,
                         const BoundBox& bbox,
                         const std::vector< Point >& pts,
                         double nsIncrement,
                         double weIncrement,
                         long nptsNS,
                         long nptsWE);
   virtual ~RegularLatLonGrid();

   /// Overridden functions
   virtual std::string hash() const { return hash_;}
   virtual const char* gridType() const { return "regular_ll"; }
   virtual BoundBox boundingBox() const { return bbox_;}
   virtual size_t nPoints() const { return points_.size(); }
   virtual void coordinates( Grid::Coords & ) const;
   /// @deprecated will be removed soon as it exposes the inner storage of the coordinates
   virtual const std::vector<Point>& coordinates() const { return points_; }

   /// Functions specific to Regular Lat long grids
   Point latLon(size_t lat, size_t lon) const;
   long rows() const { return nptsNS_;}
   long cols() const { return nptsWE_;}
   double incLat() const { return nsIncrement_; }
   double incLon() const { return weIncrement_; }

private:
   std::string hash_;
   BoundBox bbox_;
   double nsIncrement_;             /// In degrees
   double weIncrement_;             /// In degrees
   long nptsNS_;
   long nptsWE_;
   std::vector< Point > points_;     ///< storage of coordinate points

   /// Added friend mechanism to minimize data copying
   friend class GribRegularLatLonGrid;
};

//-----------------------------------------------------------------------------

} // namespace grid
} // namespace eckit

#endif
