inherit "/world/area";
#include <const.h>
#include <sys/rtlimits.h>
#include <landmark.h>

/** This area object is very similar to the normal area object, except that
 * it is used for holding a different room style -- "overworld" rooms, which
 * are all the same size, run into each other, and use the area's tiled map
 * as terrain instead of a key on rooms.
 */

string *adjacent_areas;
string *minerals;

/** Initializes the area object; the default area is 'blank'.
 * Note that init_exits is called in the create() function to
 * set up the exits object properly (this is necessary for
 * inheriting that object.
 */
create() {
   ::create();
   name = "_blank_maparea";
   adjacent_areas = ({ "", "", "", "" });
}

string *query_minerals() {
   return minerals;
}

void set_minerals( string *x ) {
   minerals = x;
}

void set_adjacent_area( int i, string s ) {
   object ob;

   if( !s ) {
      adjacent_areas[i] = "";
      return;
   }
   ob = find_room( s, this_object() );
   if( !ob ) return;
   adjacent_areas[i] = get_location(ob);
   if( previous_object() != ob ) // Prevent too-deep recursion!
      ob->set_adjacent_area( (i+2)%4, get_location(this_object()) );
}

object query_adjacent_area( int i ) {
   return find_room( adjacent_areas[i], this_object() );
}

object query_east_area() {
   return find_room(adjacent_areas[0], this_object());
}

void set_east_area( string s ) {
   set_adjacent_area( 0, s );
}

object query_north_area() {
   return find_room(adjacent_areas[1], this_object());
}

void set_north_area( string s ) {
   set_adjacent_area( 1, s );
}

object query_west_area() {
   return find_room(adjacent_areas[2], this_object());
}

void set_west_area( string s ) {
   set_adjacent_area( 2, s );
}

object query_south_area() {
   return find_room(adjacent_areas[3], this_object());
}

void set_south_area( string s ) {
   set_adjacent_area( 3, s );
}

string *query_adjacent_areas() {
   return adjacent_areas;
}

void set_adjacent_areas( string *s ) {
   if( pointerp(s) && sizeof(s) == 4 )
      adjacent_areas = s;
}

int query_is_world_map() {
   return 1;
}

string query_grid_chunk( int pos ) {
   string chunk;
   int gpos, iy, cx, cy, cz;

   chunk = "";
   cx = CX(pos); cy = CY(pos); cz = CZ(pos);
   for( iy = 0; iy < OVERWORLD_HEIGHT; iy++ ) {
      gpos = (iy + cy) * grid_xdim + cz * grid_xdim * grid_ydim + cx;
      chunk += grid[gpos..gpos + OVERWORLD_WIDTH - 1];
   }

   return chunk;
}

mixed get_room( int ix, int iy ) {
   object ob;
   string full_loc = 0;
   if( ix < 0 && (ob = query_west_area()) )
      full_loc = ob->get_room( ix + ob->query_xdim(), iy );
   if( iy < 0 && (ob = query_north_area()) )
      full_loc = ob->get_room( ix, iy + ob->query_ydim() );
   if( ix >= query_xdim() && (ob = query_east_area()) )
      full_loc = ob->get_room( ix - query_xdim(), iy );
   if( iy >= query_ydim() && (ob = query_south_area()) )
      full_loc = ob->get_room( ix, iy - query_ydim() );
   if ( full_loc ) {
      if ( member(full_loc, ';') >= 0 ) {
         return full_loc;
      } else {
         return get_location(ob) + ";" + full_loc;
      }
   }

   if( ix < 0 || iy < 0 || ix >= query_xdim() || iy >= query_ydim() ) return 0;
   return "room_" + MAKE_C(ix, iy, 0);
}

void unlimited_roomgen();

void generate_rooms() {
   msg( "==> [Notice] Generating rooms..." );
   limited( #'unlimited_roomgen, ({ LIMIT_UNLIMITED }) );
   msg( "==> [Notice] Rooms generated." );
}

void reap_room(object room) {
   foreach(object ob : filter(
         all_inventory(room), (: $1->query_is_landscape() :)
      )
   )
      destruct(ob);
   destruct(room);
}

void unlimited_roomgen( object src_area ) {
   int ix, iy, xdim, ydim;
   object ob;
   mapping dead_rooms;
   mapping std_exits = ([ "north", "west", "south", "east" ]);
   string link;
   if( !src_area ) src_area = this_object();

   dead_rooms = ([ ]);
   debug("Cleaning exits");
   foreach( ob : all_inventory(src_area) ) {
      if( ob->query_map_room() ) {
         object iexit;

         dead_rooms["room_" + MAKE_C(ob->query_x(), ob->query_y(), 0)] = ob;
         foreach( iexit : filter(all_inventory(ob), (:
            load_name($1) == "/world/exit/outdoors" :)) ) {
            if( member(std_exits, iexit->query_dir()) ) destruct(iexit);
         }
      }
   }
   xdim = query_xdim();
   ydim = query_ydim();
   debug("Generating rooms");
   for( ix = 0; ix <= xdim - OVERWORLD_WIDTH; ix += OVERWORLD_WIDTH )
   for( iy = 0; iy <= ydim - OVERWORLD_HEIGHT; iy += OVERWORLD_HEIGHT ) {
      object exit_ob;

      ob = dead_rooms["room_" + MAKE_C(ix, iy, 0)];
      if( !ob ) {
         ob = clone_object( "/world/maproom" );
         ob->move( this_object() );
         ob->set_coord( MAKE_C(ix, iy, 0) );
      }
      else {
         ob->move( this_object() );
         dead_rooms -= ([ "room_" + MAKE_C(ix, iy, 0) ]);
      }
      if( (link = get_room(ix + OVERWORLD_WIDTH, iy)) &&
         !present("exit_east", ob) ) {
         exit_ob = clone_object( "/world/exit/outdoors" );
         exit_ob->move(ob);
         exit_ob->set_dir("east");
         exit_ob->set_link( link );
         exit_ob->check_backlink( 1 );
      }
      if( (link = get_room(ix - OVERWORLD_WIDTH, iy)) &&
         !present("exit_west", ob) ) {
         exit_ob = clone_object( "/world/exit/outdoors" );
         exit_ob->move(ob);
         exit_ob->set_dir("west");
         exit_ob->set_link( link );
         exit_ob->check_backlink( 1 );
      }
      if( (link = get_room(ix, iy + OVERWORLD_HEIGHT)) &&
         !present("exit_south", ob) ) {
         exit_ob = clone_object( "/world/exit/outdoors" );
         exit_ob->move(ob);
         exit_ob->set_dir("south");
         exit_ob->set_link( link );
         exit_ob->check_backlink( 1 );
      }
      if( (link = get_room(ix, iy - OVERWORLD_HEIGHT)) &&
         !present("exit_north", ob) ) {
         exit_ob = clone_object( "/world/exit/outdoors" );
         exit_ob->move(ob);
         exit_ob->set_dir("north");
         exit_ob->set_link( link );
         exit_ob->check_backlink( 1 );
      }
   }
   foreach( ob : dead_rooms ) {
      reap_room(dead_rooms[ob]);
   }
   foreach( ob : filter(all_inventory(), (: $1->query_map_room() :)) )
      "/daemon/map"->generate_scenery( query_grid_chunk(ob->query_coord()), ob );
}

int query_cell_index( int x, int y, int z ) {
   if( x >= query_xdim() && query_adjacent_area( 0 ) )
      return query_adjacent_area( 0 )->query_cell_index( x - query_xdim(), y, z );
   if( y < 0 && query_adjacent_area( 1 ) )
      return query_adjacent_area( 1 )->query_cell_index( x, y + query_adjacent_area( 1 )->query_ydim(), z );
   if( x < 0 && query_adjacent_area( 2 ) )
      return query_adjacent_area( 2 )->query_cell_index( x + query_adjacent_area( 2 )->query_xdim(), y, z );
   if( y >= query_ydim() && query_adjacent_area( 3 ) )
      return query_adjacent_area( 3 )->query_cell_index( x, y - query_ydim(), z );
   if( x < 0 || x >= query_xdim() || y < 0 || y >= query_ydim() ) return -1;
   return ::query_cell_index( x, y, z );
}

/** Returns a mapping giving enough information to
 * remap from the original area to the one responsible
 * for the given coordinates.
 */
mapping query_nearby_area( int x, int y, int z ) {
   if( x >= query_xdim() && query_adjacent_area( 0 ) )
      return query_adjacent_area( 0 )->query_nearby_area( x - query_xdim(), y, z );
   if( y < 0 && query_adjacent_area( 1 ) )
      return query_adjacent_area( 1 )->query_nearby_area( x, y + query_adjacent_area( 1 )->query_ydim(), z );
   if( x < 0 && query_adjacent_area( 2 ) )
      return query_adjacent_area( 2 )->query_nearby_area( x + query_adjacent_area( 2 )->query_xdim(), y, z );
   if( y >= query_ydim() && query_adjacent_area( 3 ) )
      return query_adjacent_area( 3 )->query_nearby_area( x, y - query_ydim(), z );
   if( x < 0 || x >= query_xdim() || y < 0 || y >= query_ydim() ) return 0;
   return ([ "object" : this_object(), "x" : x, "y" : y, "z" : z ]);
}
