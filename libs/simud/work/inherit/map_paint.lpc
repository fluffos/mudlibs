#include <coord.h>
#include <const.h>
#include <const/shapeconst.h>
#include <sys/regexp.h>

// Paint mode: Make a list of all objects at a location
#define PAINT_POS     1
// Paint mode: Add painted coordinates to used_coords, for collision checking.
#define PAINT_SOLID 2
// Paint mode: Find all the objects falling within a certain shape.
#define PAINT_SHAPE   3
// Paint mode: Find all the objects falling within a certain shape.
#define PAINT_COORDS  4
// Paint mode: Record paint commands for sending to a graphical client.
#define PAINT_RECORD  5

/** A highly nasty piece of code for handling all the map painting.
 * This has been pretty tightly integrated with most of the MUDlib,
 * although it should still be possible to yank it back out if
 * you want to get rid of maps. Most of the code that uses it is
 * designed to work even if no map is available.
 */

// Prototypes
void paint_map( string name );
void paint_small_map( string name );
string query_zbuf();
string query_curr_map();

/// Data saving the state of the map.
nosave string small_map, curr_map, map, zbuf, base_zbuf, path_chart, paint_record;
nosave int *colors, *curr_colors;
nosave string *color_table;
nosave mapping floor_chars = FLOOR_CHARS;

/** Room adjacency information. Same dimensions as the small_map.
 * Value is an "array of four bytes", packed into a single integer.
 * x&0xFF is the room to the right of the cell, x&0xFF00 is above,
 * x&0xFF0000 is the room to the left, and x&0xFF000000 is below.
 * As usual, a value of 255 means that the cell in question is
 * empty. Note that a room may be adjacent to itself...
 */
nosave int *adjacent_cells;
/// The dimensions of the map
nosave int map_xdim, map_ydim, small_map_xdim, small_map_ydim;
/// Paint states for the map
nosave int paint_pos, paint_mode;
/// 1: Yes, I have a map. -1: No, I don't. 0: I don't know, have to check.
nosave int has_map, has_small_map;
/// An accumulator for special mode painting (for finding objects in a region, etc.)
nosave object *objs;
/// An accumulator for finding the nearest adjacent empty cell to an object.
nosave mapping used_coords;

string get_color_code( int cval ) {
//   write("get_color_code("+cval+")\n");
   return "~[" + ((cval&15)/10) + ((cval&15)%10) + ((cval>>4)&7);
}

void _create_map_paint() {
   int i;
   color_table = allocate( 129 );
   for( i = 0; i <= 128; i++ ) {
      color_table[i] = get_color_code( i );
   }
}

/** A mostly internal function -- turns all the colors on the map to the
 * default gray. This is done before redrawing to get all the colors right,
 * since the wall-drawing routine doesn't set color as well.
 */
void clear_colors() {
   colors = allocate( map_xdim * map_ydim, 7 );
}

/** Forces the map to redraw from scratch next time it's requested. Do this
 * if you change the shape of the map in the area or modify the scenery, so
 * that it will refresh the map with the new rendering.
 */
void clear_map() {
   has_map = 0;
   has_small_map = 0;
   path_chart = 0;
}

/** \return True, if the object has a grid, but false otherwise.
 * This sets an internal flag to remember if this object has a map.
 */
int query_has_map() {
   return 1;
}

/** \return True, if the map is painted, 0 if it isn't, and -1 if this object has no map.
 */
int query_map_painted() {
   return has_map;
}

/// \return The x dimension (number of columns sideways) of the fully rendered map.
int query_map_xdim() {
   if( !has_small_map ) paint_small_map( this_object()->query_name() );
   if( has_small_map < 0 ) return 0;
   return map_xdim;
}

/// \return The y dimension (number of rows) of the fully rendered map.
int query_map_ydim() {
   if( !has_small_map ) paint_small_map( this_object()->query_name() );
   if( has_small_map < 0 ) return 0;
   return map_ydim;
}

/// \return The number of cells wide that this map is.
int query_small_map_xdim() {
   if( !has_small_map ) paint_small_map( this_object()->query_name() );
   if( has_small_map < 0 ) return 0;
   return small_map_xdim;
}

/// \return The number of cells high that this map is.
int query_small_map_ydim() {
   if( !has_small_map ) paint_small_map( this_object()->query_name() );
   if( has_small_map < 0 ) return 0;
   return small_map_ydim;
}

/// \return An array of cell adjacency information
int *query_adjacent_cells() {
   if( !has_small_map ) paint_small_map( this_object()->query_name() );
   if( has_small_map < 0 ) return 0;
   return adjacent_cells;
}

int *query_adjacency( int i ) {
   if( !has_small_map ) paint_small_map( this_object()->query_name() );
   if( has_small_map < 0 ) return 0;
   if( i < 0 || i >= sizeof(adjacent_cells) ) return 0;
   return ({ adjacent_cells[i] & 0xFF,
             (adjacent_cells[i] & 0xFF00) >> 8,
             (adjacent_cells[i] & 0xFF0000) >> 16,
             ((adjacent_cells[i] & 0xFF000000) >> 24) & 0xFF });
}

object *query_adjacent_rooms( int pos ) {
   mixed *ob;
   int i, x, y, z;

   if( !has_small_map ) paint_small_map( this_object()->query_name() );
   if( has_small_map < 0 ) return 0;
   x = this_object()->query_x() + environment(this_object())->query_x();
   y = this_object()->query_y() + environment(this_object())->query_y();
   z = this_object()->query_z() + environment(this_object())->query_z();
   ob = query_adjacency( pos );
   if( !ob ) return 0;
   for( i = 0; i < 4; i++ ) {
      if( ob[i] == 254 )
         ob[i] = 0;
      else
         ob[i] = find_room( environment(this_object())->query_grid_value(ob[i]), environment(this_object()) );
   }

   return ob;
}

int query_coord() {
   if( !has_small_map ) paint_small_map( this_object()->query_name() );
   return ::query_coord();
}

// gpfault:  Used to sort objects in ascending y
int coord_compare(object a, object b) {
}

void paint_small_map( string name ) {
   object ob, env;
   int i, j;
   mapping curr_exit, *exit_list;
   int worldx, worldy, worldz;
   string grid, err;

   env = environment(this_object());
   if( !env ) return; // Not ready to paint yet.

   if( !this_object()->query_map_room() ) {
      string my_tile;
      int left_min, right_max, my_index;

      // Get the index used to designate cells belonging to this room
      my_index = env->query_room_index( name );
      if( my_index < 0 ) {
         has_small_map = -1;
         return; // Not listed
      }

      // Set map_xdim to the width of the area. We'll adjust this as we go.
      map_xdim = env->query_xdim();

      // Setup my_tile, a one-char string giving the cell type for this room's cells.
      my_index++;
      grid = env->query_grid();
      my_tile = " "; my_tile[0] = my_index;

      // We also figure out our world positioning from here,
      // so initialize that...
      // AMH: WAS querying coords from env, but that turns out
      // to be pretty useless...
      worldx = 0;
      worldy = 0;
      worldz = 0;

      // Strip off leading lines from the grid
      i = j = 0; // Floors are stored sequentially, so these are delta_y and delta_z...
      while( strstr( grid[..map_xdim-1], my_tile, 0 ) < 0 ) {
         grid = grid[map_xdim..];
         i++;
         if( i >= env->query_ydim() ) {
            j++;
            i = 0;
         }
      }
      worldy += i;
      worldz += j;
      // Strip off trailing lines
      while( strstr( grid[<map_xdim..], my_tile, 0 ) < 0 ) {
         grid = grid[..<map_xdim+1];
      }

      // Figure out how many leading and trailing spaces to clip.
      left_min = map_xdim - 1; right_max = 0;
      for( i = strlen(grid) - map_xdim; i >= 0; i -= map_xdim ) {
         j = strstr( grid[i..i+map_xdim-1], my_tile, 0 );
         if( j < 0 ) continue;
         if( j < left_min ) left_min = j;
         do {
            if( j >= map_xdim ) write("WARN!\n");
            if( j > right_max ) right_max = j;
         } while( (j = strstr(grid[i..i+map_xdim-1], my_tile, j+1)) > 0 );
      }
      worldx += left_min;
      // Strip leading and trailing columns
      for( i = strlen(grid) - map_xdim; i >= 0; i -= map_xdim )
         grid[i..i+map_xdim-1] = grid[i+left_min..i+right_max];
      map_xdim = right_max - left_min + 1;
      map_ydim = strlen(grid) / map_xdim;
      // Convert to the right form for rendering with the daemon.
      // AL - escaped my_tile because indices 91 and 93 are [ and ] in ascii
      //      and like to wreak severe havoc on us when this happens [11/23/04]
     // Take Three:
     //      Just escaping []'s in the hopes that they're the only problem
     //      children, everything before [ works... - al [8/26/05]
     // Take Four:
     //      Handle these chars the hard way. Replace them manually.
     // Take Five:
     //      I read the bloody PCRE man page... trying \Q...\E
      if( my_tile == "[" || my_tile == "^" ) {
         my_tile = "\Q \E";
         my_tile[1] = my_index;
      }
      if( my_index == '\\' || my_index == ']' ) {
         int c;
         debug( "initiating stupid room #92/93 hack" );
         for( c = 0; c < strlen(grid); c++ )
            grid[c] = (grid[c]==my_index?' ':'\255');
     } else {
         if( err = catch(grid = regreplace( grid, "[^"+my_tile+"]", "\255", 1 )) ) {
            debug( "caught stupid map regexp error" );
          debug( "err = "+err );
            debug( "room = "+this_object()->query_name() );
            debug( "my_index = "+my_index+" my_tile = '"+as_lpc(my_tile)+"'" );
          debug( "grid = "+as_lpc(grid) );
          return;
        }
         grid = regreplace( grid, "["+my_tile+"]", " ", 1 );
        if( member(grid, ' ') == -1 )
            debug( this_object()->query_name() + " (#"+my_index+") has empty map" );
     }
      // AL - apparently... things do not like escaping chars either. Rooms
      //      with indices like 48 (ascii '0') wind up as \0 and such for some
      //      stupid reason. So... I've actually removed the escape chars for
      //      now. This just means that areas are currently limited to 90 rooms
      //      in size until the two lines above are swapped out.

      // Cache my calculated world coordinates
      this_object()->set_coord( MAKE_C(worldx, worldy, worldz) );

      // Cache the mini-map version of the room
      small_map = grid;
   }
   else {
      int rx, ry, rcoord;
      worldx = CX(::query_coord());
      worldy = CY(::query_coord());
      worldz = CZ(::query_coord());
      zbuf = "/daemon/map"->base_world_zbuf();

      if( sscanf(name, "%~s_%d.%d", rx, ry) != 3 ) {
         debug("Cannot paint room " + object_name() + ", name format must be <name>_<x>.<y> (name is "+name+")");
         has_small_map = -1;
         return;
      }
      rcoord = MAKE_C(rx,ry,0);

      grid = env->query_grid_chunk( rcoord );
      if( sizeof(grid) != OVERWORLD_WIDTH * OVERWORLD_HEIGHT ) {
         debug("Outsize room " + object_name() + ", probably is outside of allowed boundary for area.");
         has_small_map = -1;
         return;
      }
      // Mini-map is trivially simple...
      small_map = tab(" ", OVERWORLD_WIDTH * OVERWORLD_HEIGHT);

      map_xdim = OVERWORLD_WIDTH;
      map_ydim = OVERWORLD_HEIGHT;
   }

   // Had to move this up to avoid recursion attempting to get room coords...
   has_small_map = 1;

   // A brief diversion to build the adjacency grid.
   adjacent_cells = allocate( map_xdim * map_ydim );

   j = this_object()->query_z(); // Temp: j = the room's z coordinate in the area
   for( i = map_xdim * map_ydim; i--; ) {
      int cx, cy;
      cx = (i % map_xdim) + this_object()->query_x();
      cy = (i / map_xdim) + this_object()->query_y();
      adjacent_cells[i] =
         (env->query_cell_index(cx + 1, cy, j) & 0xFF) |
         ((env->query_cell_index(cx, cy - 1, j) << 8) & 0xFF00) |
         ((env->query_cell_index(cx - 1, cy, j) << 16) & 0xFF0000) |
         ((env->query_cell_index(cx, cy + 1, j) << 24) & 0xFF000000);
   }

   // Note: up until now, map_xdim and map_ydim have been
   // in world coordinates. Now we scale them up to match
   // the ASCII representation's coordinates.
   // The old dim's are preserved for later querying.
   small_map_xdim = map_xdim;
   small_map_ydim = map_ydim;
   map_xdim = map_xdim * 5 + 2;
   map_ydim = map_ydim * 3 + 2;
}

/** This function completely draws the map, based on data gleaned
 * from the surrounding area object. It is pretty slow. If you need
 * to update the map (because some permanent scenery has changed,
 * for example), you should call clear_map(), and this will be called
 * as soon as the map data is needed again. You generally shouldn't
 * need to call this function directly.
 *
 * \a name The name to use in looking up the room information.
 * You could theoretically use this to draw a map that doesn't belong
 * to this room (although the environment of this_object() would
 * have to have the name listed).
 */
void paint_map( string name ) {
   int i, j;
   object ob, env;

   paint_mode = 0;

   env = environment(this_object());
   if( !env ) return; // Not ready to paint yet.

   // This is the algorithm for painting rooms with an arbitrary
   // shape. The else clause is for painting rooms in the overworld.
   if( !this_object()->query_map_room() ) {
      paint_small_map( name );

      // Actually draw the darn thing, and cache it in "map".
      // Still uncolored, at this point.
      map = "/daemon/map"->make_map( small_map, small_map_xdim, small_map_ydim );
      if( has_small_map == -1 ) {
         has_map = -1;
         return;
      }

      zbuf = "/daemon/map"->query_zbuf();
   }
   // Variables that must be set here:
   // worldx, worldy, worldz, coord
   // small_map, map (grid doesn't need to be set)
   // map_xdim, map_ydim, small_map_xdim, small_map_ydim
   else {
      paint_small_map( name );
      if( has_small_map == -1 ) {
         has_map = -1;
         return;
      }

      map = "/daemon/map"->base_world_map();
   }

   clear_colors();

   curr_map = map;
   curr_colors = colors; // Pointer copy only -- is OK.

   if( this_object()->query_map_room() )
      "/daemon/map"->paint_world_map(this_object(), env->query_grid_chunk(MAKE_C(this_object()->query_x(), this_object()->query_y(),0)) );

   foreach( ob : all_inventory(this_object()) ) {
      if( !ob->query_is_landscape() ) continue;
      ob->on_map_paint( this_object() );
   }

   foreach( ob : all_inventory(this_object()) ) {
      if( ob->query_is_landscape() ) continue;
      ob->on_map_paint( this_object() );
   }

   base_zbuf = zbuf;

   map = curr_map;
   colors = copy(curr_colors);
   has_map = 1;
}

/** \return The small map itself (i.e. a map of the cells). Cells which do
 * not belong to the room are '\255', anything else belongs (generally,
 * this should be spaces: ' ').
 */
string query_small_map() {
   if( !has_small_map ) paint_small_map( this_object()->query_name() );
   if( has_small_map < 0 ) return 0;
   return small_map;
}

/// \return 1 if the given coordinate is valid on this map. No-map rooms are always valid.
int query_valid_square(int x, int y) {
   int index;
   string smap;

   smap = query_small_map();
   x = (x - 1) / 5;
   y = (y - 1) / 3;
   if( x < 0 || y < 0 || x >= small_map_xdim || y >= small_map_ydim ) return 0;
   if( small_map[x + y * small_map_xdim] == 32 ) return 1;
   else return 0;
}

string query_curr_map() {
   object ob;
   int i, next_pos;
   string colored_map, pos_map;

   paint_mode = 0;
   if( !has_map ) paint_map( this_object()->query_name() );
   if( has_map < 0 ) return 0;
   curr_map = map;
   zbuf = base_zbuf;
   foreach( ob : all_inventory(this_object()) )
      ob->on_paint( this_object() );
//      debug( as_string(ob)+"->on_paint(...)");
   return curr_map;
}

string query_map() {
   object ob;
   int i, next_pos, cpos, clen;
   string *colored_map;
   int *pos_map;

//   msg("Start: " + utime()[0] + ":" + utime()[1]);
   paint_mode = 0;
   if( !has_map ) paint_map( this_object()->query_name() );
   if( has_map < 0 ) return 0;
   curr_map = map;
   curr_colors = copy(colors);
   if( !map ) return 0;
//   msg("After setup (cache=faster): " + utime()[0] + ":" + utime()[1]);
   zbuf = base_zbuf;
   foreach( ob : all_inventory(this_object()) )
      ob->on_paint( this_object() );
//   msg("After paint: " + utime()[0] + ":" + utime()[1]);

   pos_map = ({ 0 });
   for( i = 1; i < sizeof(curr_colors); i++ )
      if( curr_colors[i] != curr_colors[i-1] ) pos_map += ({ i });
   pos_map += ({ sizeof(curr_colors) });
   colored_map = ({ });
   next_pos = 0;
//   write("pos_map is " +pos_map );
   cpos = 0;
   clen = sizeof(curr_colors);
//   msg("After color setup: " + utime()[0] + ":" + utime()[1]);
   for( i = 0; i < clen; i = next_pos ) {
      next_pos = pos_map[cpos+1];
      colored_map += ({ color_table[curr_colors[pos_map[cpos]]] + curr_map[i + (i/map_xdim)..(next_pos-1) + ((next_pos) / map_xdim)] });
      cpos++;
   }
//   msg("After color build: " + utime()[0] + ":" + utime()[1]);

   return implode( colored_map, "" );
}

int get_position( int x, int y ) {
   if( !has_map ) paint_map( this_object()->query_name() );
   if( has_map < 0 ) return 0;
   if( x < 0 || y < 0 || x >= map_xdim || y >= map_ydim ) return 0;
   return curr_map[ x + y * (map_xdim+1) ];
}

int get_tiletype( int x, int y ) {
   if( !has_map ) paint_map( this_object()->query_name() );
   if( has_map < 0 ) return 0;
   if( x < 0 || y < 0 || x >= map_xdim || y >= map_ydim ) return 0;
   return zbuf[ x + y * map_xdim ];
}

/** Used for painting maps. This function is usable by both on_map_paint
 * and on_paint events, but won't work as expected anywhere else (certain
 * initialization has to happen for painting to work predictably).
 *
 * In a nutshell, this paints the character \a sym at x, y on this
 * object's map, unless it is clipped in the z buffer, which is determined
 * using the z height value (see /include/const.h LAYER_xxx constants for
 * available z values). The color is a bit-packed value -- the bottom 4
 * bits are the foreground color (ANSI standards, add 8 for brighter
 * values), and the 3 bits above are the background color. If you
 * set the highest bit, then the background color is modified to match
 * whatever is underneath the painted object (objects which return
 * true on 'query_is_landscape()' are always painted first, to mitigate
 * the paint-ordering problem that this creates).
 */
varargs void paint( int x, int y, int sym, int color, int z ) {
   int pos;
   switch( paint_mode ) {
      case PAINT_POS:
         if( x + y * map_xdim + z * map_xdim * map_ydim == paint_pos )
         objs += ({ previous_object() });
      return;
      case PAINT_SOLID:
         if( !member(FLOOR_CHARS, z + '0') ) used_coords += ([ MAKE_C( x, y, 0 ) ]);
      return;
      case PAINT_SHAPE:
         if( member(used_coords, MAKE_C(x + 4096 - CX(paint_pos), y + 4096 - CY(paint_pos), 0)) )
            objs += ({ previous_object() });
      return;
      case PAINT_COORDS:
         used_coords += ([ MAKE_C( x, y, 0 ) ]);
      return;
      case PAINT_RECORD:
         string ptmp = "12345";
         ptmp[0] = x + ' ';
         ptmp[1] = y + ' ';
         ptmp[2] = z + '0';
         ptmp[3] = color + 32;
         ptmp[4] = sym;
         paint_record += ptmp;
      return;
   }
   if( x < 0 || y < 0 || x >= map_xdim || y >= map_ydim ) return;
   pos = x + y * map_xdim;
   // Drawing under an overlay
   if( zbuf[pos] - '0' == LAYER_OVERLAY && z != LAYER_OVERLAY ) {
      // Draw floor under overlay -- do nothing
      if( member(floor_chars, z + '0') ) return;
      // Draw wall under overlay -- block
      zbuf[pos] = LAYER_OVERLAY_S + '0';
      return;
   }
   // Normal z buffer behavior
   else {
      if( z == LAYER_OVERLAY && !member(floor_chars, zbuf[pos]) )
         z = LAYER_OVERLAY_S; // Overlays can't make "bridges"
      if( zbuf[pos] > z + '0' ) return;
   }
   zbuf[pos] = z + '0';
   curr_map[ x + y * (map_xdim+1) ] = sym;
   if( color & 0x80 )
      curr_colors[pos] = (curr_colors[pos] & 0xF0) + (color & 0xF);
   else
      curr_colors[pos] = color;
}

/// A utility function to paint a row of characters at a time.
void paint_row( int x, int y, string syms, int color, int z ) {
   int i;

   for( i = strlen(syms); i--; )
      paint( x + i, y, syms[i], color, z );
}

/** Allows you to paint a monochromatic sprite-like object.
 * Basically, you can think of \a vals as a string of commands:
 *
 * Start with the cursor at x, y.
 * Any character: Paint the character, move cursor right one space.
 * Newline (\\n): Move the cursor to x, cursor_y+1
 * Tab (\\t): Move the cursor one right, paint nothing.
 */
void paint_shape( int x, int y, string vals, int color, int z ) {
   int i, ix, iy;

   ix = x; iy = y;
   for( i = 0; i < strlen(vals); i++ ) {
      if( vals[i] == '\t' ) ix++;
      else if( vals[i] == '\n' ) {
         ix = x;
         iy++;
      }
      else
         paint( ix++, iy, vals[i], color, z );
   }
}

/** A higher performance, unclipped paint function used for painting overworld
 * maps. It's faster, but it takes off the kid gloves. Errors using this
 * will show up as such. It paints in 5x3 blocks.
 *
 * If \a color is an integer, then it will be painted in that solid color. If
 * it's a string (must be 15 characters), then it will be used as a color key.
 *
 * Same goes for zbuffer values ... integer will be padded, string used directly.
 * The zbuffer is ignored for painting, but is set directly.
 */
varargs void paint_tile( int x, int y, string block, mixed color, mixed z ) {
   int ipos, iposoffs;
   string zbufvals;
   int *colvals;

   if( stringp(z) ) zbufvals = z;
   else {
      zbufvals = " ";
      zbufvals[0] = z + '0';
      zbufvals = tab( zbufvals, 15 );
   }

   if( stringp(color) ) colvals = to_array(color);
   else if( pointerp(color) ) colvals = color;
   else {
      colvals = allocate(15, color); // For integer color value
   }

//   debug("curr_map len is "+strlen(curr_map)+", block len is "+strlen(block));

   ipos = x + y * map_xdim;
   curr_colors[ipos..ipos+4] = colvals[0..4];
   zbuf[ipos..ipos+4] = zbufvals[0..4];
   // The +y on these is to make up for curr_map's \n's.
   curr_map[ipos+y..ipos+y+4] = block[0..4];

   ipos += map_xdim; y++;
   curr_colors[ipos..ipos+4] = colvals[5..9];
   zbuf[ipos..ipos+4] = zbufvals[5..9];
   curr_map[ipos+y..ipos+y+4] = block[5..9];

   ipos += map_xdim; y++;
   curr_colors[ipos..ipos+4] = colvals[10..14];
   zbuf[ipos..ipos+4] = zbufvals[10..14];
   curr_map[ipos+y..ipos+y+4] = block[10..14];
}

/** This behaves identically to paint_tile, except that it respects the zbuffer
 * in its painting. This means that objects in the room can use it, but you
 * should expect a performance hit.
 */
varargs void paint_tile_clipped( int x, int y, string block, mixed color, mixed z ) {
   int icol, ipos, iposoffs;
   string zbufvals;
   int *colvals;

   if( stringp(z) ) zbufvals = z;
   else {
      zbufvals = " ";
      zbufvals[0] = z + '0';
      zbufvals = tab( zbufvals, 15 );
   }

   if( stringp(color) ) colvals = to_array(color);
   else if( pointerp(color) ) colvals = color;
   else {
      colvals = allocate(15, color); // For integer color value
   }

   ipos = x + y * map_xdim;
   for( icol = 0; icol < 5; icol++ )
   if( zbuf[ipos+icol] <= zbufvals[icol] ) {
      curr_colors[ipos+icol] = colvals[icol];
      zbuf[ipos+icol] = zbufvals[icol];
      curr_map[ipos+icol+y] = block[icol];
   }
   ipos += map_xdim; y++;

   for( icol = 0; icol < 5; icol++ )
   if( zbuf[ipos+icol] <= zbufvals[icol+5] ) {
      curr_colors[ipos+icol] = colvals[icol+5];
      zbuf[ipos+icol] = zbufvals[icol+5];
      curr_map[ipos+icol+y] = block[icol+5];
   }
   ipos += map_xdim; y++;

   for( icol = 0; icol < 5; icol++ )
   if( zbuf[ipos+icol] <= zbufvals[icol+10] ) {
      curr_colors[ipos+icol] = colvals[icol+10];
      zbuf[ipos+icol] = zbufvals[icol+10];
      curr_map[ipos+icol+y] = block[icol+10];
   }
}

mapping get_shape( object ob ) {
   mapping out;
   int ipos, obpos, old_mode;

   used_coords = ([ ]);
   old_mode = paint_mode;
   paint_mode = PAINT_COORDS;

   ob->on_map_paint( this_object() );
   ob->on_paint( this_object() );
   obpos = ob->query_coord();
   obpos = MAKE_C(4096-CX(obpos), 4096-CY(obpos), 32-CZ(obpos));

   out = ([ ]);
   foreach( ipos : used_coords )
      out += ([ ipos + obpos ]);

   paint_mode = old_mode;

   return out;
}

string query_zbuf() {
   object ob;

   paint_mode = 0;
   if( !has_map ) paint_map( this_object()->query_name() );
   if( has_map < 0 ) return 0;
   curr_map = map;
   zbuf = base_zbuf;
   foreach( ob : all_inventory(this_object()) )
      ob->on_paint( this_object() );
   return zbuf;
}

string query_base_zbuf() {
   if( !has_map ) paint_map( this_object()->query_name() );
   if( has_map < 0 ) return 0;
   return base_zbuf;
}

int query_zbuf_pos( int coord ) {
   if( !has_map ) paint_map( this_object()->query_name() );
   if( has_map < 0 ) return 0;
   if( CX(coord) >= map_xdim || CY(coord) >= map_ydim ) return 0;
   return base_zbuf[CX(coord) + CY(coord) * map_xdim];
}

varargs object *get_contents( int x, int y, int z ) {
   object ob;

   if( !has_map ) paint_map( this_object()->query_name() );
   if( has_map < 0 ) return 0;
   paint_mode = PAINT_POS;
   paint_pos = x + y * map_xdim + z * map_xdim * map_ydim;
   objs = ({ });
   foreach( ob : all_inventory(this_object()) )
      ob->on_paint( this_object() );
   return objs;
}

/** Get a list of all the objects in the room who fall
 * in the \a shape centered at \a origin. For sample
 * shapes, see the walk daemon (/daemon/walk).
 */
object *get_region( int origin, mapping shape ) {
   object ob, *oblist;
   mapping offshape;
   int ipos;

//   if( !has_map ) paint_map( this_object()->query_name() );
//   if( has_map < 0 ) return 0;
   oblist = ({ });
   offshape = ([ ]);
   if( !mappingp(shape) ) raise_error("Invalid shape passed to get_region: " + as_lpc(shape));
   // Offset the shape
   foreach( ipos : shape )
      offshape += ([ ipos + origin ]);

   // Loop through objects, doing shape matches
   foreach( ob : all_inventory() ) {
      int obpos;
      mapping obshape, offobshape;

      obpos = ob->query_coord();
      obshape = ob->query_shape();
      if( !obpos && !obshape ) continue; // 0,0,0, shape is 0: Assume it's an invisible object.
      if( !obshape ) obshape = ([ MAKE_C(4096, 4096, 32) ]);
      offobshape = ([ ]);
      foreach( ipos : obshape )
         offobshape += ([ ipos + obpos ]);
      if( sizeof(offshape - offobshape) != sizeof(offshape) ) oblist += ({ ob });
   }

   return oblist;
}

/** Clips shape so that only squares which are actually
 * free are included. \a shape is offset by origin.
 * "Free" is defined as "you can walk on top of whatever
 * it is," so there might be objects in the region returned,
 * but they are walkable. In this case, origin is assumed
 * to be an UNSIGNED coordinate.
 *
 * \param use_base_zbuf uses only the cached z-buffer, and doesn't
 * draw any objects; use this to prevent recursion (some
 * objects call this from within their paint routines).
 * \param legal_layers is a mapping of layers which are
 * considered 'walkable'; if you pass in 0 or don't include it,
 * the default FLOOR_CHARS are used.
 */
varargs mapping get_empty_shape( int origin, mapping shape, int use_base_zbuf, mapping legal_layers ) {
   mapping clipped_shape;
   string zbuf;
   int ipos, xdim, ydim;

   // Signed coord is more useful...
   origin = SMAKE_C(CX(origin), CY(origin), CZ(origin));
   if( !mappingp(legal_layers) )
      legal_layers = FLOOR_CHARS;
//   debug("Entering get_empty_shape, has_map is " + has_map );
   if( use_base_zbuf )
      zbuf = query_base_zbuf();
   else
      zbuf = query_zbuf();
   if( !zbuf ) return 0;
   shape = SHAPE_OFFSET(shape, origin);
   clipped_shape = copy(shape);
//   msg("shape is " + as_lpc(clipped_shape) + " origin=" + MAKE_CSTR(origin) );
   xdim = query_map_xdim();
   ydim = query_map_ydim();
   // Clip against the z buffer.
   foreach( ipos : shape ) {
      if( SCX(ipos) < 0 ||
         SCX(ipos) >= xdim ||
         SCY(ipos) < 0 ||
         SCY(ipos) >= ydim ||
         !member(legal_layers, zbuf[SCX(ipos) + SCY(ipos) * xdim]) ) {
         clipped_shape -= ([ ipos ]);
//         msg("Removing " + SMAKE_CSTR(ipos));
      }
   }

   return SHAPE_OFFSET(clipped_shape, SINVERT_C(origin));
}

/** If x,y,z is empty (i.e. walkable), it'll return it as a coordinate.
 * Otherwise, it will try to find the closest possible square (on the xy
 * plane) and return its position. Useful for validating positions. If
 * \a exclude is given, then that object is excluded (generally this
 * is the object for which you're seeking an empty position, so it
 * doesn't block itself).
 */
varargs int get_empty( int x, int y, int z, object exclude ) {
   object ob;
   int val, sx, sy, ix, iy, dist;

   query_base_zbuf();
   if( !base_zbuf ) return 0;
   paint_mode = PAINT_SOLID;
   used_coords = ([ ]);
   foreach( ob : all_inventory(this_object()) )
   if( ob != exclude )
      ob->on_paint(this_object());

   for( dist = 0; dist < 30; dist++ )
   // Loops ix and iy around in a square, of radius dist. Really.
   // "You are not expected to understand this."
   for( ix = x - dist, iy = y - dist; ix <= x + dist && iy <= y + dist;
      iy == y-dist ?
         (ix < x + dist ? ix++ : (ix = x - dist, iy++))
      : iy != y+dist?
         (ix == x-dist? ix = x + dist : (ix = x - dist, iy++))
         : ix++ ) {
      if( ix > 0 && iy > 0 && ix < map_xdim - 1 && iy < map_ydim - 1 ) {
         sx = (ix-1)/5; sy = (iy-1)/3;
         if( small_map[sx + sy * small_map_xdim + z * small_map_xdim * small_map_ydim] == ' ' &&
             member(FLOOR_CHARS, base_zbuf[ix + iy * map_xdim]) &&
             !member(used_coords, MAKE_C(ix, iy, 0)) ) {
               return MAKE_C(ix,iy,z);
         }
      }
   }
   return -1;
}

string get_path_chart() {
   int xdim, ydim, seed_pos, label;
   string zbuf;
   mapping open_queue, closed_queue;

   if( path_chart )
      return path_chart;

   xdim = query_map_xdim();
   ydim = query_map_ydim();

   zbuf = query_zbuf();
   // Need to do a flood-fill to build this one.
   // Start with an all-invalid path chart.
   path_chart = tab( "\255", xdim * ydim );
   zbuf = regreplace( zbuf,
      "[" + to_string(m_indices(FLOOR_CHARS)) + "]",
      "\255", RE_GLOBAL
   );
//   debug( "Initial zbuf is " + as_lpc(zbuf), "map" );
   label = ' ';
   // This peforms a flood-fill of the individual pockets of walkable
   // space.
   while( (seed_pos = member(zbuf, 255)) != -1 ) {
      open_queue = ([ seed_pos ]);
      closed_queue = ([ ]);
      while( sizeof(open_queue) ) {
         int curr_open;
         int x, y;
         foreach( curr_open : open_queue ) {
            m_add( closed_queue, curr_open );
            m_delete( open_queue, curr_open );
            if( zbuf[curr_open] != '\255' )
               continue;
            zbuf[curr_open] = 254;
            path_chart[curr_open] = label;
            x = curr_open % xdim;
            y = curr_open / xdim;
            if( x - 1 > 0 && !member(closed_queue, curr_open-1) )
               m_add( open_queue, curr_open - 1 );
            if( x + 1 < xdim && !member(closed_queue, curr_open+1) )
               m_add( open_queue, curr_open + 1 );
            if( y - 1 > 0 && !member(closed_queue, curr_open-xdim) )
               m_add( open_queue, curr_open-xdim );
            if( y + 1 < ydim && !member(closed_queue, curr_open+xdim) )
               m_add( open_queue, curr_open+xdim );
         }
      }
      ++label;
   }
   return path_chart;
}

int query_can_reach( int x1, int y1, int x2, int y2 ) {
   int xdim = query_map_xdim(), ydim = query_map_ydim();
   if( !path_chart ) get_path_chart();

   // Out-of-bounds coords always illegal.
   if( x1 < 0 || y1 < 0 || x1 >= xdim || y1 >= ydim ||
      x2 < 0 || y2 < 0 || x2 >= xdim || y2 >= ydim )
      return 0;
   int start_cell = path_chart[x1 + y1 * xdim],
      end_cell = path_chart[x2 + y2 * xdim];
   // If starting point is a solid wall, allow everything
   // (maybe hackable, but hopefully avoids sticking).
   if( start_cell == 255 )
      return 1;
   // If start and end position match...
   if( start_cell == end_cell )
      return 1;
   // If final position is a solid wall (like room exits)...
   if( end_cell == 255 ) {
      // If any of the ADJACENT squares match, we allow this.
      if( x2 > 0 && path_chart[(x2-1) + y2 * xdim] == start_cell )
         return 1;
      if( y2 > 0 && path_chart[x2 + (y2-1) * xdim] == start_cell )
         return 1;
      if( x2 < xdim - 1 && path_chart[(x2+1) + y2 * xdim] == start_cell )
         return 1;
      if( y2 < ydim - 1 && path_chart[x2 + (y2+1) * xdim] == start_cell )
         return 1;
   }
   return 0;
}

int query_path_cell( int x, int y ) {
   int xdim = query_map_xdim();
   get_path_chart();
   if( x < 0 || y < 0 || x >= xdim || y >= query_map_ydim() )
      return -1;
   return path_chart[x + y * xdim];
}

string query_raw_map() {
   paint_mode = 0;
   if( !has_map ) paint_map( this_object()->query_name() );
   if( has_map < 0 ) return 0;
   if( map[<1] != '\n' ) map += "\n";
   return query_map_xdim() + "\n" + query_map_ydim() + "\n" + map + to_string( map(colors,(:($1&0x7f)+32:)) ) + base_zbuf;
}

string query_full_overlay() {
   object ob;
   string *ret = ({ });
   paint_mode = PAINT_RECORD;
   foreach( ob : all_inventory(this_object()) ) {
      paint_record = "";
      ob->on_paint( this_object() );
      if( paint_record != "" ) {
         ret += ({ "" + ob->query_name() + ob->query_unique_id() });
         ret += ({ paint_record });
      }
   }
   paint_mode = 0;
   paint_record = 0; // Conserve memory.
   return implode( ret, "\n" );
}

string query_obj_overlay( object ob ) {
   string ret;
   paint_mode = PAINT_RECORD;
   paint_record = "";
   ob->on_paint( this_object() );
   if( paint_record != "" ) {
      ret = "" + ob->query_name() + ob->query_unique_id() + "\n" +
         paint_record;
   }
   else ret = "";
   paint_mode = 0;
   paint_record = 0; // Conserve memory.
   return ret;
}
