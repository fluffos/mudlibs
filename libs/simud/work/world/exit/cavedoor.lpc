/** This exit type is for doors. Will make them
 * openable later...
 */

#include <const.h>
#include <const/battconst.h>
#include <const/shapeconst.h>
#include <coord.h>
inherit "/world/exit/twoway";

/** The shape depends on the direction of the exit. North/south
 * exits are a horizontal strip five chars wide; East/west are
 * a vertical strip 3 high. Upward exits are <<, and downward
 * exits (or any other direction) are >>.
 */
mapping exit_shape() {
   switch( query_dir() ) {
   case "north": case "south":
      return
         ([ query_coord() + MAKE_C(4094,4096,32),
            query_coord() + MAKE_C(4095,4096,32),
            query_coord() + MAKE_C(4096,4096,32),
            query_coord() + MAKE_C(4097,4096,32),
            query_coord() + MAKE_C(4098,4096,32) ]);
   case "east": case "west":
      return
         ([ query_coord() + MAKE_C(4096,4095,32),
            query_coord() + MAKE_C(4096,4096,32),
            query_coord() + MAKE_C(4096,4097,32) ]);
   default:
      return
         ([ query_coord() + MAKE_C(4096,4096,32),
            query_coord() + MAKE_C(4097,4096,32)
         ]);
   }
}

/** Draw the exit. If you are writing your own exit type, you
 * should override this function
 */
void on_map_paint( object painter ) {
   int p;
   mapping draw_shape;
   int draw_char;

   draw_shape = exit_shape();
   if( !draw_shape ) return;
   if( query_dir() == "up" )
      draw_char = '<';
   else if( sizeof(draw_shape) == 2 )
      draw_char = '>';
   else
      draw_char = '.';

   foreach( p : draw_shape )
      painter->paint( CX(p)-4096, CY(p)-4096, draw_char, 0x08, LAYER_INVALID );
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

   dir = query_dir();
   dest_room = get_destination();
   if( !dest_room ) {
      msg("Exit exists, but the destination does not exist. Report a bug.");
      return 0;
   }
   walk_dest = exit_shape();
   // Note that "unclipped" is set, since exits are sometimes outside of room boundaries.
   if( sizeof(walk_dest) )
      WALK_DAEMON->init_walk_action( exit_shape(), 0,
         ({ 0, this_object(), this_player(), ST_STANDING, 0 }), 1 );
   else
      this_object()->on_action(0);
   return 1;
}

/** Walk through an exit after arriving at it.
 */
void on_action( object target ) {
   object dest_room, backlink;
   string *messages;
   mapping m;
   int dx, dy;
   int closest;

   // Something else already moved me; quietly abort.
   if( environment(this_player()) != environment() )
      return;

   dest_room = get_destination();

   this_player()->move_player( dest_room, "door", "the " + query_dir() + " passage" );

   backlink = query_backlink();
   if( backlink ) {
      dx = backlink->query_x();
      dy = backlink->query_y();


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

   if( query_dir() )
      return "Go " + query_dir();
   else
      return "Enter cave";
}

int query_out_backlink() {
   return 1;
}
