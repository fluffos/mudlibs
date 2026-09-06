#include <const/battconst.h>
#include <const/shapeconst.h>
#include <coord.h>
#include <shape.h>
#include <desc.h>
#include <lockable.h>
inherit "/world/exit/twoway";

/** This exit type is for the city gate.
 */

void on_action( object target );

LOOK( "A large, sturdy city gate, heavily built from bars of iron." )

/** Erk, conflict between desc & twoway here! This is ugly.
 */
string query_name() {
   return "exit_" + MCALL(query_dir());
}

string query_distant() {
   QBODY( "distant", "a gate" );
}

string query_specific() {
   QBODY( "specific", "the " + MCALL(query_dir()) + " gate" );
}

int query_scenery() { return 1; } // Don't show up on list of objects in room.

/** Just returns a point, offset by the position of the door. Moves
 * with its parent building, if it has one.
 */
mapping exit_shape() {
   switch( MCALL(query_dir()) ) {
      case "west":
      case "east":
         return SHAPE_OFFSET( SHAPE_BOX(1,4), MCALL(query_coord()) + MAKE_C(4096, 4096-1, 32) );
      case "north":
      case "south":
         return SHAPE_OFFSET( SHAPE_BOX(5,1), MCALL(query_coord()) + MAKE_C(4096-2, 4096, 32) );
   }
}

mapping query_shape() {
   return SHAPE_OFFSET(MCALL(exit_shape()), SMAKE_C(-query_x(), -query_y(), -query_z()));
}

/** Draw the exit. If you are writing your own exit type, you
 * should override this function
 */
void on_paint( object painter ) {
   int p = MCALL( query_coord() );
   int x = MCALL(query_x()), y = MCALL(query_y());

   switch( MCALL(query_dir()) ) {
      case "north":
         if( query_closed() ) {
            painter->paint_row( x-1, y-4, "___", 0x80, LAYER_INVALID );
            painter->paint_shape( x-2, y-3, "//|\\\\\n|||||\n|||||", 0x70, LAYER_INVALID );
            painter->paint_row( x-2, y, query_locked() ? "xxxxx" : "+++++", 0x8f, LAYER_INVALID );
         }
         else {
            painter->paint_row( x-1, y-4, "___", 0x80, LAYER_INVALID );
            painter->paint_shape( x-2, y-3, "/   \\\n|   |\n|   |", 0x70, LAYER_INVALID );
            painter->paint_row( x-2, y, ".....", 0x8f, LAYER_INVALID );
         }
         break;
      case "south":
         if( query_closed() ) {
            painter->paint_row( x-1, y+1, "___", 0x80, LAYER_INVALID );
            painter->paint_row( x-2, y, query_locked() ? "xxxxx" : "+++++", 0x8f, LAYER_INVALID );
            painter->paint_shape( x-2, y+2, "//|\\\\\n|||||\n|||||", 0x70, LAYER_INVALID );
         }
         else {
            painter->paint_row( x-1, y+1, "___", 0x80, LAYER_INVALID );
            painter->paint_row( x-2, y, ".....", 0x8f, LAYER_INVALID );
            painter->paint_shape( x-2, y+2, "/   \\\n|   |\n|   |", 0x70, LAYER_INVALID );
         }
         break;
      case "east":
         painter->paint_shape( x + 1, y - 2, "||\n||\n||\n||\n||\n||", 0x70, LAYER_INVALID );
         if( query_closed() )
            painter->paint_shape( x, y - 1, query_locked() ? "x\nx\nx\nx" : "+\n+\n+\n+", 0x8f, LAYER_INVALID );
         else
            painter->paint_shape( x, y - 1, ".\n.\n.\n.", 0x8f, LAYER_INVALID );
         break;
      case "west":
         painter->paint_shape( x - 2, y - 2, "||\n||\n||\n||\n||\n||", 0x70, LAYER_INVALID );
         if( query_closed() )
            painter->paint_shape( x, y - 1, query_locked() ? "x\nx\nx\nx" : "+\n+\n+\n+", 0x8f, LAYER_INVALID );
         else
            painter->paint_shape( x, y - 1, ".\n.\n.\n.", 0x8f, LAYER_INVALID );
         break;
   }
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

   if( query_closed() ) {
      msg("The gate is closed, and impassable.");
      return 1;
   }

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

   this_player()->move_player( dest_room, "gate", query_specific() );

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

   if( param == "exit_gate" || param == "exit_" + door_dir ) return match_ob;
   if( param[0..2] == "in " && param[3..] == dir ) return match_ob;
   if( param[0..4] == "into " && param[5..] == dir ) return match_ob;
   if( param == door_dir + " gate" || param == "gate" ) return match_ob;
   up_ob = ::id(param);
   if( up_ob == this_object() ) return match_ob;
   return up_ob;
}
