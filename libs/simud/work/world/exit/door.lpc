#include <lockable.h>
inherit "/world/exit/basedoor";

/** This exit type is for doors that can open,
 * close, and have locks installed.
 */

LOOK( "~Name is a rather ordinary looking wooden door. It is capable of opening and closing. Currently, it is ?(ISCLOSED:closed):(open)." )
PLURAL( "doors" )

/** Draw the exit. This adds the capability of drawing a closed (+) door.
 */
void on_paint( object painter ) {
   int p;
   mapping draw_shape = MCALL(exit_shape());

   if( !draw_shape ) return;
   foreach( p : draw_shape )
      painter->paint(
         CX(p)-4096,
         CY(p)-4096,
            query_closed() ? (query_locked() ? 'x' : '+') : (query_locked() ? ',' : '.'), 0x8F, LAYER_INVALID
      );
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
   if( query_closed() ) {
      msg("You would slam yourself embarassingly against the closed door if you tried to go through it.");
      return 1;
   }

   return ::exit_action();
}

object id( string param ) {
   if( (param == "open door" && !query_closed()) ||
      (param == "closed door" && query_closed()) ) return this_object();

   return ::id(param);
}

int on_open() {
   int closed = query_closed();
   ::on_open();
   if( closed != query_closed() ) {
      object outside;

      outside = MCALL(query_backlink());
      set_target( outside );
      msg_room( environment(outside), "~CACT~Subt ~vertopen.~CDEF" );
   }
   return 1;
}

int on_close() {
   int closed = query_closed();
   ::on_close();
   if( closed != query_closed() ) {
      object outside;

      outside = MCALL(query_backlink());
      set_target( outside );
      msg_room( environment(outside), "~CACT~Subt ~vertclose.~CDEF" );
   }
   return 1;
}
