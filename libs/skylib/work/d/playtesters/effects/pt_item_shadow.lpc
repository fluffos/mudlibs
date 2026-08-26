/*
 * Stops anyone but the pt who checked this armour out using the
 * armour, and makes the armour worth nothing.
 *
 */

#include <move_failures.h>

inherit "/std/effect_shadow";

/** @ignore yes */
string query_owner() { return arg(); }

/** @ignore yes */
mixed query_property( mixed prop ) {
    if( prop == NO_RECYCLE )
        return 1;

    if( player )
        return player->query_property(prop);

    return 0;

} /* query_property() */

/** @ignore yes */
private int playtester_check( object thing ) {
    if( objectp(thing) ) {
        if( userp( thing ) && !playtesterp( thing ) )
            return 0;
        if( !thing->query_corpse() && thing->query_name() != arg() )
            return 0;
    }

    return 1;

} /* playtester_check() */

/** @ignore yes */
int set_holder( object thing, int pos ) {
    if( !playtester_check( thing ) )
        return 0;
   return player->set_holder( thing, pos );
} /* set_holder() */

/** @ignore yes */
int set_worn_by( object thing ) {
    if( !playtester_check( thing ) )
        return 0;
    return player->set_worn_by( thing );
} /* set_holder() */

/** @ignore yes */
varargs int move( mixed dest, string msgin, string msgout ) {
    if( objectp(dest) && userp(dest) && !playtesterp(dest) )
        return MOVE_INVALID_DEST;
    if(!player) return 1;
    return player->move( dest, msgin, msgout );
} /* move() */

/** @ignore yes */
int query_no_steal() { return 1; }

/** @ignore yes */
int query_value() { return 0; }
