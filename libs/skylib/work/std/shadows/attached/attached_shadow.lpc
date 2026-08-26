/**
 * Generic shadow for attached effects.
 * @author Taffyd
 */

#include <effect.h>

inherit "/std/effect_shadow";

int taken_off( object ob, string effect ) {
    int i;
    class effect *wear_effects;

    if ( ob == player ) {
         wear_effects = ob->query_effs();
    
         for ( i = 0; i < sizeof( wear_effects ); i++ ) {
             if ( wear_effects[ i ]->ob_name == effect ) {
                 remove_this_effect();
                 break;
             }
         }                
    }

    return player->taken_off( ob, effect );
} /* taken_off() */

