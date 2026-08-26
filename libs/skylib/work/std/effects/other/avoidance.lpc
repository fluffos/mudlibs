/**
 * This effect makes an NPC avoid certain people.
 * It can be used to make NPCs run from certain players
 * if they attack the NPC or similar.
 * The first argument to the effect is the name of the
 * player to avoid, the second is the time to keep
 * avoiding the player.
 * @example add_effect("/std/effects/other/avoidance",
 *                   ({ player->query_name(), 600 }) );
 */

#include "path.h"
#include <effect.h>

#define PLAYER arg[ 0 ]
#define TIME   arg[ 1 ]

/** @ignore yes */
string query_classification() { return "mind.avoidance"; }

/** @ignore yes */
string query_shadow_ob() { return SHADOWS +"avoidance"; }

/** @ignore yes */
int survive_death() { return 1; }

/** @ignore yes */
mapping beginning( object player, mixed arg, int id ) {
    player->submit_ee("reduce_avoidance", 60, EE_CONTINUOUS );
    return ([ PLAYER : TIME ]);
} /* beginning() */

/** @ignore yes */
mapping merge_effect( object player, mapping old_arg, mixed arg, int id ) {
    old_arg[PLAYER] += TIME;
    return old_arg;
} /* merge_effect() */

void reduce_avoidance( object player, mapping arg, int id ) {
    string person;

    if( !mapp(arg) || !sizeof( arg ) ) {
        player->submit_ee( 0, 0, EE_REMOVE );
        return;
    }

    foreach( person in keys(arg) ) {
        arg[person] -= 60;
        if( arg[person] < 30 )
            map_delete( arg, person );
    }

    player->set_arg_of( (int)player->sid_to_enum( id ), arg );

} /* reduce_avoidance() */
