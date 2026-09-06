/** This exit type is for doors that cannot close.
 */

#include <const.h>
#include <const/battconst.h>
#include <coord.h>
#include <shape.h>
#include <embed.h>
#include <desc.h>
inherit "/world/exit/twoway";

void on_action( object target );

DISTANT( "a door" )
LOOK( "An open door frame." )
PLURAL( "doors" )
TYPE( "door" )

/** Erk, conflict between desc & twoway here! This is ugly.
 */
string query_name() {
   return "exit_" + MCALL(query_dir());
}

string query_default_specific() {
   string val;
   if( query_host() ) {
      string owner;
      owner = query_host()->query_owner();
      if( owner )
         return "the door to " + capitalize(owner) + "'s " + query_host()->query_name();
      else
         return "the " + query_host()->query_name() +  " door";
   }
   else return "the door";
}

int query_scenery() { return 1; } // Don't show up on list of objects in room.

/** Just returns a point, offset by the position of the door. Moves
 * with its parent building, if it has one.
 */
mapping exit_shape() {
   object host;
   int coord;

   host = MCALL(query_host());
   coord = MCALL(query_coord());

   if( objectp(host) )
      return ([ MAKE_C(4096, 4096, 32) + coord + host->query_coord() ]);
   else
      return ([ MAKE_C(4096, 4096, 32) + coord ]);
}

/** Draw the exit. If you are writing your own exit type, you
 * should override this function
 */
void on_paint( object painter ) {
   int p;
   mapping draw_shape = MCALL(exit_shape());

   if( !draw_shape ) return;
   foreach( p : draw_shape )
      painter->paint( CX(p)-4096, CY(p)-4096, '.', 0x8F, LAYER_INVALID );
}

/** This actually causes the player to pass through the exit.
 * \a m is the mapping with the exit information; if you want information
 * about the player or the room, use this_player() and environment(this_player())
 * respectively. An error message is printed if the exit fails.
 *
 * A fair amount of error checking has already been done on \a m, so the core
 * information is most likely valid.
 *
 * \return True on success, false on failure.
 */
int exit_action() {
   string dir;
   object dest_room;
   mapping walk_dest;

   if( previous_object()->query_is_mirror() ) {
      dir = previous_object()->query_dir();
      dest_room = environment();
      walk_dest = previous_object()->exit_shape();
   }
   else {
      dir = query_dir();
      dest_room = get_destination();
      if( !dest_room ) {
         msg("Exit exists, but the destination does not exist. Report a bug.");
         return 0;
      }
      walk_dest = exit_shape();
   }
   // Note that "unclipped" is set, since exits are sometimes outside of room boundaries.
   if( sizeof(walk_dest) ) {
      WALK_DAEMON->init_walk_action( walk_dest, 0,
         ({ 0, (previous_object()->query_is_mirror()?previous_object():this_object()), this_player(), ST_STANDING, 0 }), 1 );
   }
   else {
      MCALL( on_action(0) );
   }
   return 1;
}

/** Walk through an exit after arriving at it.
 */
void on_action( object target ) {
   object dest_room, backlink;
   mapping m;
   int dx, dy;
   int closest;
   string dir;

   if( previous_object()->query_is_mirror() ) {
      dest_room = environment();
      dir = previous_object()->query_dir();
      backlink = this_object();
   }
   else {
      dest_room = get_destination();
      dir = query_dir();
      backlink = query_backlink();
   }

   if( dir == "out" && environment(this_player()) && environment(environment(this_player())) && environment(environment(this_player()))->query_specific() )
      this_player()->move_player( dest_room, "leave", environment(environment(this_player()))->query_specific() );
   else {
      if( query_type() == "door" )
         this_player()->move_player( dest_room, "door", query_specific() );
      else
         this_player()->move_player( dest_room, query_type(), query_dir() );
   }

   if( backlink ) {
      object alt_host;
      dx = backlink->query_x();
      dy = backlink->query_y();
      if( alt_host = backlink->query_host() ) {
         dx += alt_host->query_x();
         dy += alt_host->query_y();
      }

      closest = dest_room->get_empty( dx, dy );
      if( closest > 0 )
         this_player()->set_coord( closest );
   }


   // Don't waste time on room descs for NPC's, unless they're possessed.
   if( this_player()->query_is_player() || this_player()->query_possessor() )
      "/bin/look"->main();
}

string query_action_name( mixed *param ) {
   mixed m;
   string dir;

   dir = MCALL(query_dir());

   if( dir )
      return "Go " + dir;
   else
      return "Go";
}

object id( string param ) {
   object match_ob, up_ob;
   string door_dir;

   if( previous_object()->query_is_mirror() ) {
      match_ob = previous_object();
      door_dir = match_ob->query_dir();
   }
   else {
      match_ob = this_object();
      door_dir = query_dir();
   }

   if( param == "exit_" + door_dir ) return match_ob;
   if( param[0..2] == "in " && param[3..] == dir ) return match_ob;
   if( param[0..4] == "into " && param[5..] == dir ) return match_ob;
   if( param == door_dir + " " + query_type() ) return match_ob;
   up_ob = ::id(param);
   if( up_ob == this_object() ) return match_ob;
   return up_ob;
}

int query_out_backlink() {
   return 1;
}
