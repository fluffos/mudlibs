/** Designed to keep a square grid of values (0-254, stored 1-255) which index into an array of
 * other values (Typically strings). Intended, presently, for a grid stored in
 * the area which indexes into the rooms there. When you request indices, they are mapped from
 * 1-255 to 0-254 to be more familiar to users, but this is not how they're
 * stored. The reason for not storing 0's in the array is because when this was
 * written, the driver did not support storing 0's in the middle of a string.
 * This is no longer the case, but updating the code would likely break a lot
 * of things.
 */

/// The grid itself.
string grid;
/// A table (array) of the meanings of the various grid indices. Translates the grid into something meaningful.
string *grid_values;
/// Dimension of the grid (it is a 3d cube)
int grid_xdim, grid_ydim, grid_zdim;
/// Wipes the values off the grid (setting them to 254; actually 255, but all values are offset by 1 so that \0 is -1).
void clear_grid() {
   grid_values = 0;
   if( grid_xdim > 0 && grid_ydim > 0 && grid_zdim > 0 ) grid = tab( "\255", grid_xdim * grid_ydim * grid_zdim );
   else grid = 0;
}

/** Sets the grid size to xdim by ydim and then clears
 * the grid. There is some attempt to preserve the values
 * that were on the grid before, but if you shrink it you'll
 * obviously lose something.
 */
void resize_grid( int xdim, int ydim, int zdim ) {
   string old_grid = grid;
   int ix, iy, iz, nx = grid_xdim, ny = grid_ydim, nz = grid_zdim;

   grid_xdim = xdim;
   grid_ydim = ydim;
   grid_zdim = zdim;
   if( !(xdim == 0 && ydim == 0 && zdim == 0) && (xdim == 0 || ydim == 0 || zdim == 0) )
      raise_error("Perfectly flat but non-zero grid not allowed.");
   clear_grid();

   if( stringp(old_grid) && stringp(grid) )
   for( iz = 0; iz < zdim && iz < nz; iz++ )
   for( iy = 0; iy < ydim && iy < ny; iy++ )
   for( ix = 0; ix < xdim && ix < nx; ix++ )
      grid[ix + iy * xdim + iz * xdim * ydim] = old_grid[ix + iy * nx + iz * nx * ny];
}

/** Allows you to shift the grid around. Useful if you want to add more rooms on the left side, i.e.
 * The amount to shift by is given as a delta value in x, y, and z.
 */
void offset_grid( int dx, int dy, int dz ) {
   string old_grid = grid;
   int ix, iy, iz;

   if( !stringp(grid) ) return;
   if( dx < 0 || dy < 0 || dz < 0 ) {
      debug("tiledmap::offset_grid: Only positive grid offsets allowed; it wraps, so just use query_xdim()-1 to shift left.");
      return;
   }

   for( iz = 0; iz < grid_zdim; iz++ )
   for( iy = 0; iy < grid_ydim; iy++ )
   for( ix = 0; ix < grid_xdim; ix++ ) {
      int newx, newy, newz;
      newx = (ix + dx) % grid_xdim;
      newy = (iy + dy) % grid_ydim;
      newz = (iz + dy) % grid_zdim;
      grid[newx + newy * grid_xdim + newz * grid_xdim * grid_ydim] =
         old_grid[ix + iy * grid_xdim + iz * grid_xdim * grid_ydim];
   }
}

/** Allows you to query the x-dimension of the grid. You must
 * use resize_grid() to change this dimension.
 */
int query_xdim() { return grid_xdim; }

/** Allows you to query the y-dimension of the grid. You must
 * use resize_grid() to change this dimension.
 */
int query_ydim() { return grid_ydim; }

/** Allows you to query the z-dimension of the grid. You must
 * use resize_grid() to change this dimension.
 */
int query_zdim() { return grid_zdim; }

/// If your functions want to deal with grid data directly, use this.
string query_grid() { return grid; }

/** \return The array of grid values. Primarily useful for tight inner
 * loops where you want speed over simplicity.
 */
string * query_grid_values() { return grid_values; }

/** \return The index associated with \a name. If you want the
 * literal value for the grid array, add 1 to this value.
 *
 * The value is -1 if \a name is not found in the grid values.
 * Roughly the same as member(query_grid_values(), name), but with
 * more error checking.
 */
int query_room_index( string name ) {
   if( !pointerp(grid_values) ) return -1;
   return member( grid_values, name );
}

/** \return An index directly into the grid array,
 * translated from the *local* coordinate x, y, z. Remember
 * that if you want world coordinates, you must add on
 * the offsets yourself (query_x(), query_y(), query_z()).
 */
private int coord_to_index( int x, int y, int z ) {
   if( x < 0 || y < 0 || z < 0 || x >= grid_xdim ||
      y >= grid_ydim || z >= grid_zdim )
   return -1;

   return x + y * grid_xdim + z * grid_xdim * grid_ydim;
}

/**\return -1 if something is really wrong (either there is no grid, or the coordinate
 * is out of bounds); otherwise, returns the index value of the given grid cell.
 */
int query_cell_index( int x, int y, int z ) {
   int i;

//   if( !stringp(grid) ) return -1;

   i = coord_to_index(x, y, z);
   if( i < 0 ) return i;
   return 0xff & (grid[i] - 1);
}

/** Returns the grid value for a cell, referenced into the array
 * of grid values. Returns 0 if no value is available (Note that
 * you will generally get a zero back for empty cells).
 */
string query_cell( int x, int y, int z ) {
   int i;

//   if( !pointerp(grid_values) || !stringp(grid) ) return 0;
   i = query_cell_index( x, y, z );
   if( i < 0 || i >= sizeof(grid_values) ) return 0;

   return grid_values[i];
}

/// \return The \a i 'th entry from the grid values (grid values are usually room references).
string query_grid_value( int i ) {
   if( !pointerp(grid_values) ) return 0;
   if( i >= sizeof(grid_values) || i < 0 ) return 0;
   return grid_values[i];
}

/// Initialize all of the grid values at once. Allows for external editing.
void set_grid_values( string *list ) {
   grid_values = list;
}

/** Lets you set the cell at position x, y, z in the grid to
 * a given value c. \a c maps into the array of grid values as an index.
 * Note that x, y, z are local coordinates, relative to the grid. If you
 * have world coordinates, you must adjust them first.
 *
 * To "blank out" a value, pass in -1 for c.
 *
 * \return True on success, false on error (invalid values).
 */
int set_cell_index( int x, int y, int z, int c ) {
   int i;

   if( c == -1 ) c = 254;
   if( c < 0 || c > 254 ) return 0;
//   if( !stringp(grid) ) return 0;
//   if( strlen(grid) < grid_xdim * grid_ydim ) return 0;

   i = coord_to_index( x, y, z );
   if( i == -1 ) return 0;
   c++;
   grid[i] = c;
   return 1;
}

/** The high level "convenient" way to set room values.
 * It will search grid_values for a value matching \a val,
 * and create it if there is room and it's not present.
 * It will then use the relevant index for the grid position.
 *
 * \return True on success, false otherwise.
 *
 * \param val The string value to set at position \a x, \ay, \a z.
 */
int set_cell( int x, int y, int z, string val ) {
   int i, j;
   object ob;

//   if( !stringp(grid) ) return 0;
   if( !pointerp(grid_values) ) grid_values = ({ });
   if( (i = member(grid_values, val)) == -1 ) {
      i = member(grid_values, 0);
      if( i == -1 ) {
         if( sizeof(grid_values) >= 255 ) return 0;
         i = sizeof(grid_values);
         grid_values += ({ val });
      }
      else
         grid_values[i] = val;
   }

   if( ob = present(grid_values[i], this_object()) )
      ob->room_update();

   j = coord_to_index( x, y, z );
   if( j < 0 ) return 0;
   grid[j] = i+1;
   return 1;
}

/** Calls this to remove all data related to entry /a name in this
 * map. This could be used, for example, to reset the data for a
 * room in the area inheriting this object.
 *
 * \return True if any data was removed, false if there was nothing to remove.
 */
int remove_grid_value( string name ) {
   int i;
   string c;

   if( (i = member(grid_values, name)) == -1 )
      return 0; // No such name.

   grid_values[i] = 0;
   while( sizeof(grid_values) > 0 && grid_values[<1] == 0 ) grid_values = grid_values[..<2];

   c = " ";
   c[0] = i + 1;
   grid = implode( explode(grid, c), "\255" );
   return 1;
}

/** Calls this to blank out a single cell. This has the additional
 * effect of deleting the room from the grid_values list if the
 * cell deleted was the last instance of that room on the map.
 *
 * \return True if removing the cell deleted the room completely,
 * false if not.
 */
int remove_cell( int x, int y, int z ) {
   int i;
   string c;
   object ob;

   i = coord_to_index( x, y, z );
   c = " ";
   c[0] = grid[i];
   while( sizeof(grid_values) > 0 && grid_values[<1] == 0 ) grid_values = grid_values[..<2];
   if( c == "\255" ) return 0; // Blank cell already.
   grid[i] = 255;
   if( sizeof(grid_values) >= c[0] ) {
      // updates the room, if it already exists
      if( ob = present(grid_values[c[0]-1], this_object()) )
         ob->room_update();
      if( member(grid, c[0]) < 0 ) {
         grid_values[c[0]-1] = 0;
         return 1;
      }
   }
   return 0;
}

/** Sets entry \a i of the grid values to \a val.
 *
 * \return True on success, false if any of the inputs are invalid
 * (You need to make sure that 0 >= i >= 254).
 */
int set_grid_value( int i, string val ) {
   if( i > 254 || i < 0 ) return 0;
   if( !pointerp(grid_values) ) grid_values = allocate(i+1);
   if( sizeof(grid_values) < i + 1 ) grid_values += allocate(i + 1 - sizeof(grid_values));

   grid_values[i] = val;
   return 1;
}

/** Makes the coordinate code behave; slight conflict with the map_paint()
 * implementation, but it isn't severe, and you shouldn't be using tiledmap
 * and map_paint together in the same object anyway.
 */
int query_has_map() {
   return 1;
}
