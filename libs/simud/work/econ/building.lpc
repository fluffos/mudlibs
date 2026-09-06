#include <inven.h>
#include <desc.h>
#include <scenedesc.h>
#include <object.h>
#include <tiledmap.h>
#include <coord.h>
#include <shape.h>
#include <const/exitsconst.h>
#include <room_paths.h>

int query_is_building() { return 1; }
string building_info() { return "hp\nmaxhp"; }
string query_owner();

string owner;
symbol larder;
int last_food_total;

object query_larder() {
   if( !symbolp(larder) ) return 0;
   return find_objectref( larder );
}

void set_larder( object ob ) {
   larder = to_objectref( ob );
}

varargs int query_food_total( object where ) {
   object ob;
   if( !where ) where = query_larder();
   if( !where ) return 0;
   int total = 0;
   foreach( ob : all_inventory(where) )
      total += ob->query_food_value();
   return total;
}

/** If food is offered to this building, take as much as it seems
 * likely we'll need.
 */
void on_supply( object container ) {
   object *foods = filter( all_inventory(container), (: $1->query_is_edible() :) );
   object dest = query_larder();
   if( sizeof(foods) == 0 || !dest ) return;
   // Figure out how much food and drink we have.
   int curr_total = query_food_total();
   int food_used = last_food_total - curr_total;
   // If we have no food at all, always try and keep a little
   // on hand.
   if( last_food_total <= 0 ) food_used = 30;
   // If we're not using food, don't fetch anymore.
   if( food_used <= 0 ) return;
   last_food_total = curr_total;
   // Try to hit a total of double the amount used, at least.
   while( query_food_total() < 2 * food_used && sizeof(foods) > 0 ) {
      object ob = foods[0];
      // Could split by quantity but meh...
      if( objectp(ob) )
         ob->move( dest );
      foods = foods[1..];
   }
}

void on_map_paint( object painter ) {
   painter->paint_shape( query_x(), query_y(), "o---o\n|...|\no-\t-o", 7, LAYER_WALL );
}

void set_coord( int coord ) {
   ::set_coord( coord );
   if( environment() ) environment()->clear_map();
}

mapping query_shape() {
   return SHAPE_BOX( 5, 3 );
}

string destructor( object ob ) {
   if( environment() ) environment()->clear_map();
   return ::destructor( ob );
}

int on_raze() {
   object ob, ob2;

   this_player()->msg_local( "~CACT~Name ~verbraze ~targ.~CDEF" );
   while( first_inventory() )
   foreach(ob : all_inventory()) {

      if(ob->query_is_living()) {
         if(ob->query_is_player()) {
            set_actor(this_player());
            set_target(ob);
            set_listener(ob);
            msg_object(ob, "You manage to slip out as ~name razes the building.");
         }
         ob->move(environment(this_object()));
         ob->set_x(query_x());
         ob->set_y(query_y());
         ob->validate_position();
      } else {
         destruct(ob);
      }
   }
   foreach( ob : all_inventory(environment()) ) {
      if( ob->query_host() == this_object() ) {
         while( first_inventory(ob) )
         foreach(ob2 : all_inventory(ob)) {
            destruct(ob2);
         }
         destruct(ob);
      }
   }
   destruct(this_object());
   return 1;
}

void set_owner( string x ) {
   owner = x;
}

string query_owner() {
   return owner;
}

int query_is_razable( object razer ) {
   if( !owner ) return 1;
   if( objectp(razer) && razer->query_name() == owner ) return 1;
   return 0;
}

// For convenience.
object make_outside_exit( object startroom, int outside_coord ) {
   object door, *env_list;
   int ienv;

   door = clone_object( "/world/exit/door" );
   door->move( environment() );
   env_list = all_inventory(environment());
   for( ienv = sizeof(env_list); ienv--; )
      if( program_name(env_list[ienv]->query_host()) == program_name() ) env_list[ienv]->move(environment());
   door->set_host( this_object() );
   door->set_dir( this_object()->query_name() );
   door->set_link( startroom->query_name() );
   door->set_coord( outside_coord );
   door->query_backlink()->set_coord(
      MAKE_C(startroom->query_map_xdim() / 2,
         startroom->query_map_ydim() - 1, 0));
   return door;
}

// Pos is the position of the door going in the direction 'dir'.
// The other door will be positioned by relative position within the
// room; this doesn't work with staircases, just with exits within
// a floor.
void link_rooms( string room1name, string room2name, int pos, string dir ) {
   object room1, room2, door;
   int dx, dy;

   room1 = find_room( room1name, this_object() );
   room2 = find_room( room2name, this_object() );
   if( !room1 || !room2 ) {
      debug( "Couldn't find room objects setting up exits: " + room1name + " or " + room2name );
      return 0;
   }
   door = clone_object( "/world/exit/door" );
   door->move( room1 );
   door->set_dir( dir );
   door->set_link( room2name );
   door->set_coord( pos );
   dx = (room1->query_x()-room2->query_x()) * 5 + ([ "west":1, "east":-1 ])[dir];
   dy = (room1->query_y()-room2->query_y()) * 3 + ([ "south":-1, "north":1 ])[dir];
   door->query_backlink()->set_coord( MAKE_C(
      dx + CX(pos),
      dy + CY(pos),
      0) );
}

// Always give the bottom floor as room1, and the top as room2.
void make_stairs( string room1name, string room2name, int pos ) {
   object room1, room2, door;
   int dx, dy;

   room1 = find_room( room1name, this_object() );
   room2 = find_room( room2name, this_object() );
   if( !room1 || !room2 ) {
      debug( "Couldn't find room objects setting up exits: " + room1name + " or " + room2name );
      return 0;
   }
   door = clone_object( "/world/exit/stairs" );
   door->move( room1 );
   door->set_dir( "up" );
   door->set_link( room2name );
   door->set_coord( pos );
   // Stairs aren't wall exits, so don't need that
   // funny compensation used in link_rooms.
   dx = (room1->query_x()-room2->query_x()) * 5;
   dy = (room1->query_y()-room2->query_y()) * 3;
   door->query_backlink()->set_coord( MAKE_C(
      dx + CX(pos),
      dy + CY(pos),
      0) );
}

// This is so that commands like 'build shack to the north' are properly explaiend.
// Buildings like /bldg/mine will override this func for themselves; /bldg/road/* doesn't
// inherit this source file
int check_direction( int dir ) {
   if ( dir == 0 )
      return 1;
   msg("For this type of building, just walk to the upper-left corner and build; do not specify a direction.");
   return -1;
}
