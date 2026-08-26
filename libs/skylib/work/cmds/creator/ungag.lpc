/**
 * Gagger object originally coded by Obilix 9 April 1997.
 * Turned into gag and ungag commands by Gruper 20 March 2000.
 */

#include <playerinfo.h>

inherit COMMAND_BASE;


int cmd( object victim ) {

   // Ungag them and log it
   if( !victim->query_gagged() )
      return notify_fail( victim->query_short() +" is not gagged.\n" );
   
   victim->delete_effect(victim->effects_matching("mudlib.gagged")[0]);
   log_file("gag.log", "On "+ctime(time())+" "+this_player()->
         query_short()+" ungagged "+victim->query_short()+".\n");
   PLAYERINFO_HANDLER->add_entry( this_player(), victim->query_name(),
         "gag", "Ungagged." );

   // Messages...
   tell_object( victim, "%^YELLOW%^Let this be a lesson to you!%^RESET%^\n" );
   this_player()->add_succeeded_mess( this_object(),
         "$N $V $I.\n", ({ victim }) );

   return 1;

} // cmd()


mixed *query_patterns() {
   return ({ "<indirect:player'player'>",
                (: cmd( $1[0] ) :) });
} /* query_patterns() */
