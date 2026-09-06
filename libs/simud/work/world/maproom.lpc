#include <inven.h>
#include <exits.h>
#include <object.h>
#include <map_paint.h>
#include <const/roomconst.h>
#include <const.h>

/// \todo Write this summary.

CAN_BUILD( 1 )
TASTE( "It tastes, well, like dirt." )

int query_can_build() {
   QBODY( "can_build", this_object()->query_default_can_build() );
}

void set_can_build( int x ) {
   SBODY( "can_build", x );
}

string query_distant() {
   return "the ground";
}

string query_specific() {
   return "the ground";
}

/// A bit flag giving the room's type (outdoors, underwater, etc.)
int room_type;

/** Dramatically simplified id() function to speed processing.
 * Only responds to roomn, where n is the value of Coord::query_coord().
 */
object id( string s ) {
   if( s == "room_" + coord || s == "room_" + CX(coord) + "." + CY(coord) ) return this_object();
   return 0;
}

string query_name() {
   return "room_" + CX(coord) + "." + CY(coord) ;
}

string query_short() {
   if( environment() ) return environment()->query_short();
   else return "A mysterious place";
}

/** \return The full description, including scenery, blocker descriptions, etc.
 * NOTE: This function may evaluate some expressions, therefore it is sometimes
 * a good idea to set the 'listener' to make sure they come out correctly.
 * The look verb does this.
 */
string query_room_desc() {
   string str, tmp, last_tmp = "";
   object ob;
   object *scenery, *buildings;
   int count;

   // Start with base description.
   str = "This is ~CBRT" + query_short() + "~CDEF.";
   // Add scenery descriptions.
   scenery = filter(all_inventory(this_object()), (: $1->query_scenery() :));
   buildings = filter( scenery, (: $1->query_is_building() :) );
   if( sizeof(buildings) > 2 ) {
      scenery -= buildings;
      str += " " + capitalize(inventory_string(buildings)) + " are built here.";
   }
   count = 1;
   foreach( ob : scenery ) {
      tmp = ob->query_scene_phrase();
      if( tmp ) {
         if ( tmp == last_tmp ) {
            count++;
         } else {
            if( strlen(last_tmp) > 0 && last_tmp[<1] != '\n' && last_tmp[<1] != ' ' ) str += " ";
            str += eval_exp(last_tmp, ob);
            if ( count > 1 )
               str += " (x" + count + ")";
            count = 1;
            last_tmp = tmp;
         }
      }
   }
   if( strlen(last_tmp) > 0 && last_tmp[<1] != '\n' && last_tmp[<1] != ' ' ) str += " ";
   str += eval_exp(last_tmp, ob);
   if ( count > 1 )
      str += " (x" + count + ")";

   str += "\n\n" + environment()->get_landmark_description(query_coord());

   return str;
}

/// \return An array of all non-scenery objects in this room.
object *query_inventory_list() {
   return filter( all_inventory(this_object()), (: !$1->query_scenery() :) );
}

/// \return The value of the room_type flag. See /include/const/roomconst.h for masks.
int query_room_type() {
   return room_type;
}

/// Sets the room type flag. See /include/const/roomconst.h for values.
int set_room_type( int x ) {
   if( intp(x) ) room_type = x;
   return room_type;
}

/// A test function to see if the object is a room. Returns true.
int query_is_room() {
   return 1;
}

int query_passable( int x, int y ) {
   int c;

   x += query_x();
   y += query_y();
   if( !environment() ) return 0;
   c = environment()->query_cell_index( x, y, 0 );
   if( c < 0 ) return 0;
   c = "/daemon/map"->query_zlevel( c );
   return member( FLOOR_CHARS, c + '0' );
}

/// Doesn't do anything for this room type!
void set_fertile() {}

/// Get the fertility at a *position*
int query_fertile( int coord ) {
   int x, y;

   if( !environment() ) return 0;

   x = (CX(coord) - 1) / 5;
   y = (CY(coord) - 1) / 3;

   if( x >= query_small_map_xdim() || x < 0 || y >= query_small_map_ydim() || y < 0 )
      return 0;

   return "/daemon/map"->query_tile_fertility()[environment()->query_cell_index(query_x() + x, query_y() + y, query_z())];
}

int query_map_room() {
   return 1;
}

int query_is_map_room() {
   return 1;
}
