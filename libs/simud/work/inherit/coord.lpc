/** Inherit this component if your object needs to have coordinates.
 *
 * There are two major coordinate systems in the game. The large,
 * global one is "world coordinates", and the smaller local one
 * is "room coordinates". Both of these coordinate systems have
 * x, y, and z components, meaning they are three dimensional.
 * This object is unable to distinguish whether it is representing
 * world or room coordinates.
 *
 * The world is divided into a 8192x8192x64 grid, and each room
 * is assigned one or more positions on that grid. This allows
 * for the MUD to reason spatially, which is often important.
 * Each room has a 5x3x1 "sub-grid" within each cell that it
 * owns, so a 2x2x1 (world coordinates) room has a 10x6x1 interior.
 * If an object is in a room, it naturally has the same world
 * coordinates as whatever cell it is in.
 */

/// The coordinate of this object.
int coord;

/// \return The coded coordinate (32 bits -- z:6 y:13 x:13, from MSB to LSB in that order).
int query_coord() {
   if( this_object()->query_has_map() )
      return coord;
   if( !environment(this_object()) )
      return 0;
   if( environment()->query_has_map() )
      return coord;
   else
      return environment()->query_coord();
}

/// Allows you to set the world coordinate with a single call. You do the encoding yourself.
void set_coord( int i ) {
   coord = i;
   refresh_room( environment(), this_object() );
   refresh_overlay( this_object() );
}

/** \return The x coordinate of this object, measuring distance from the
 * westmost point (coordinates increase left to right). If the object is
 * wider than one unit, this is the leftmost unit of the object.
 */
int query_x() {
   return query_coord() & 0x1FFF;
}

/** \return The y coordinate of this object, measured
 * from the northmost point (coordinates increase from
 * far to near, or north to south). If the object is deeper than
 * one unit, this is the northernmost unit of the object.
 */
int query_y() {
   return (query_coord() >> 13) & 0x1FFF;
}

/** \return The z coordinate of this object, measured
 * from the bottom most point (coordinates increase bottom to top).
 * If the object is thicker than one unit, this is the bottommost
 * unit.
 */
int query_z() {
   return (query_coord() >> 26) & 0x3f;
}

/// Sets the world x coordinate. Values can range from 0-8191. Higher values will be wrapped (i.e. 8192->0)
void set_x( int i ) {
   set_coord( (query_coord() & 0xFFFFE000) | (i & 0x1FFF) );
}

/// Sets the world y coordinate. Values can range from 0-8191. Higher values will be wrapped (i.e. 8192->0)
void set_y( int i ) {
   set_coord( (query_coord() & 0xFC001FFF) | ((i & 0x1FFF) << 13) );
}

/// Sets the world z coordinate. Values can range from 0-63. Higher values will be wrapped (i.e. 64->0)
void set_z( int i ) {
   set_coord( (query_coord() & 0x03FFFFFF) | ((i & 0x3F) << 26) );
}

/// \return 1 if \param x or (an object at x,y) is adjacent to this object
varargs int query_adjacent( mixed x, int y ) {
   int xdif, ydif;
   if (objectp(x)) {
      mapping bord, shape;
      if( !environment()->query_has_map() && !environment(x)->query_has_map() )
         return 1;
      shape = x->query_border();
      y=OFFSET_C(query_coord(), SINVERT_C(x->query_coord()));
      if( mappingp(shape) && member(shape, OFFSET_C(query_coord(),
         SINVERT_C(x->query_coord()))) )
         return 1;
      shape = x->query_shape();
      if( mappingp(shape) && member(shape, OFFSET_C(query_coord(),
         SINVERT_C(x->query_coord()))) )
         return 1;
      xdif = abs(query_x()-x->query_x());
      ydif = abs(query_y()-x->query_y());
   }
   else if( intp(x) ) {
      xdif = abs(query_x()-x);
      ydif = abs(query_y()-y);
   }
   else
     return 0;
   return xdif < 2 && ydif < 2;
}
