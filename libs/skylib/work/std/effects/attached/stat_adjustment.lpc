/**
 * This is the effect skelton docs.  This effect
 * has a classification of "mudlib.clothing.stat".
 * <p>
 * The argument to this effect should be a mapping with the set of
 * stat adjustments for the item and the item doing the adjusting.
 * ie: ({ ob, ([ "str" : 1, "dex" : -1 ]) })
 * <p>
 * If you add the effect with the same object twice, the new set of
 * stat adjustments overrides the old ones.
 * @classification mudlib.clothing.stat
 * @see help::effects
 * @author Pinkfish
 */

#include "path.h"
#include <effect.h>

class stat_class {
   mapping current_adjustments;
   object* obs;
   mapping *adjs;
   object me;
}

private string *_stats;

void create() {
    _stats = ({"str", "dex", "wis", "int", "con"});
} /* create() */

/** @ignore yes */
string query_classification() { return "mudlib.clothing.stat"; }

/**
 * This method adjusts bonuses on the player based on the current
 * set of stats and things.
 * @param player the player to update the stats on
 * @param arg
 */
void update_adjustments( object player, class stat_class arg ) {
    mapping stats, bing;
    string stat;
    int i, num;

    if( sizeof(arg) == 4 && arg->me != player ) {
        arg->me = player;
        arg->current_adjustments = ([ ]);
    }

    for( i = 0; i < sizeof(arg->obs); i++ ) {
        if( !arg->obs[i] ) {
            arg->obs = arg->obs[0..i -1] + arg->obs[i+1..];
            arg->adjs = arg->adjs[0..i -1] + arg->adjs[i+1..];
        }
    }

    stats = ([ ]);

    foreach( stat in _stats ) {
        num = 0;

        for( i = 0; i < sizeof(arg->adjs); i++ ) {
            bing = arg->adjs[i];

            if( bing[stat] > 0 ) {
                if( i > 0 )
                    num += bing[stat] / ( i + 1 );
                else
                    num += bing[stat];
            } else if( bing[stat] < 0 ) {
                if( i > 1 )
                    num += bing[stat] * i;
                else
                    num += bing[stat];
            } else if( i > 0 ) {
                num -= i;
            }
        }
        stats[stat] = num;
    }

    foreach( stat in _stats ) {
        if( stats[stat] != arg->current_adjustments[stat] ) {
            call_other( player, "adjust_bonus_"+stat,
                stats[stat] - arg->current_adjustments[stat] );
            arg->current_adjustments[stat] = stats[stat];
        }
    }

} /* update_adjustments() */

/** @ignore yes */
class stat_class beginning( object player, mixed arg, int id ) {
    class stat_class bing;

    bing = new( class stat_class );
    bing->current_adjustments = ([ ]);
    bing->obs = ({ arg[0] });
    bing->adjs = ({ arg[1] });
    bing->me = player;

    update_adjustments( player, bing );

    return bing;

} /* begining() */

/** @ignore yes */
int query_indefinite() { return 1; }

/** @ignore yes */
class stat_class merge_effect( object player, class stat_class old_arg,
                               mixed *new_arg ) {
    int i;

    i = member_array( new_arg[0], old_arg->obs );
    if( i != -1 ) {
        old_arg->adjs[i] = new_arg[1];
    } else {
        old_arg->obs += ({ new_arg[0] });
        old_arg->adjs += ({ new_arg[1] });
    }

    update_adjustments( player, old_arg );

    return old_arg;

} /* merge_effect() */

/** @ignore yes */
void restart( object player, class stat_class edible ) {
    update_adjustments( player, edible );
} /* restart() */

/** @ignore yes */
void quiting( object player, class stat_class womble ) {
    womble->obs = ({ });
    womble->adjs = ({ });
    update_adjustments( player, womble );
} /* restart() */

/** @ignore yes */
void end( object player, class stat_class bing ) {
    bing->obs = ({ });
    bing->adjs = ({ });
    update_adjustments( player, bing );
} /* end() */

/**
 * This method is called to remove the stat adjusts for the specified
 * id.
 * @param player the player to remove the adjustments
 * @param ob the object to remove the stats
 */
void remove_stat_adjustment_ob( object player, object ob ) {
    class stat_class fluff;
    int *ids, i;

    if( sizeof( ids = player->effects_matching(query_classification()) ) ) {
        fluff = player->arg_of(ids[0]);

        for( i = 0; i < sizeof(fluff->obs); i++ ) {
            if( fluff->obs[i] == ob ) {
                fluff->adjs = fluff->adjs[0..i-1] + fluff->adjs[i+1..];
                fluff->obs = fluff->obs[0..i-1] + fluff->obs[i+1..];
            }
        }

        if( !sizeof(fluff->obs) ) {
            player->delete_effect(ids[0]);
        } else {
            update_adjustments( player, fluff );
            player->set_arg_of( ids[0], fluff );
        }
    }

} /* remove_stat_adjustment_ob() */
