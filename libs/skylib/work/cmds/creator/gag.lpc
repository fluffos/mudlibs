/**
 * Gagger object originally coded by Obilix 9 April 1997.
 * Turned into gag and ungag commands by Gruper 20 March 2000.
 */

#include <playerinfo.h>

#define GAG_EFFECT STANDARD_DIR "/effects/other/gagged"

inherit COMMAND_BASE;

int cmd( object victim, string reason, int number ) {

   // Gag them and log it
   victim->add_effect(GAG_EFFECT, ({ number * 60, reason,
                                     lower_case(TP->query_name()) }));
//   victim->add_property( "gagged", reason, 60 * number );
   log_file( "gag.log", "On "+ ctime(time()) +" "+ this_player()->query_short()
             +" gagged "+ victim->query_short() +".\n");
   PLAYERINFO_HANDLER->add_entry( this_player(), victim->query_name(),
                                  "gag", "Gagged. Reason: "+ reason );

   // Write leetle messages about it
//   tell_object( victim,
//         "You have been gagged by "+ this_player()->query_short() +
//         ".  You will not be able to shout or chat on any channels "
//         "until the gag is removed.\n");
   
   this_player()->add_succeeded_mess( this_object(),
         "$N $V $I.\n", ({ victim }) );

   return 1;

} // cmd()


mixed *query_patterns() {
   return ({ "<indirect:player'player'> <string'reason'>",
                (: cmd( $1[0], $4[1], 120 ) :), // Default time is two hours
             "<indirect:player'player'> <string'reason'> <number'minutes'>",
                (: cmd( $1[0], $4[1], $4[2] ) :) });
} /* query_patterns() */

