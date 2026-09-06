/** A small component to handle objects that have paintable points ("spots").
 * This would include things like walls, bodies of water in custom areas, etc.
 *
 * Spots are not quite the same thing as shapes. For one thing, shapes
 * are volatile (lots of code resets your shape, i.e. to update it), whereas
 * spots remain consistent. The spots mapping is guaranteed to remain a mapping,
 * whereas if shape is a non-mapping (usually a 0) you should regenerate it.
 * Generally the shape is generated from the spots. However, the shape
 * might contain more point than the spots mapping -- this can happen with
 * objects whose 'spots' are very large, such as a wide city wall. Each
 * unit of wall might be one spot, but 5x3 units in the shape.
 */

/// A mapping of coordinates. See Coord for more information.
mapping spots = ([ ]);

/// \return The spots mapping.
mapping query_spots() {
   return spots;
}

/// Set the spots mapping directly. Guarantees that it remains a mapping. Resets the shape, if any.
void set_spots( mapping m ) {
   if( !mappingp(m) ) m = ([ ]);
   if( mappingp(m) ) spots = m;
   this_object()->set_shape( 0 );
}

/// A simple query function for checking intersection.
int query_has_spot( int pos ) {
   return member( spots, pos );
}

/// Add a spot with position \a pos to the spots mapping. Resets the shape, if any.
void add_spot( int pos ) {
   if( intp(pos) ) spots += ([ pos ]);
   this_object()->set_shape( 0 );
}

/// Remove the spot \a pos from the spots mapping. Resets the shape, if any.
void remove_spot( int pos ) {
   spots -= ([ pos ]);
   this_object()->set_shape( 0 );
}
