/*
 * This is the water breathing effect.  Allows you to breath under
 * water...
 */

inherit "/std/effects/basic";

#include <effect.h>
#include "path.h"

/** @ignore yes */
string query_shadow_ob() { return SHADOWS "water_breathing"; }

void create() {
    set_boundaries( ({ -40, -20 }), ({ 20, 40 }) );
} /* create() */

/** @ignore yes */
int query_heart_beat_frequency() { return 1; }

/** @ignore yes */
mixed effect_heart_beat( object them, int hb_no, mixed arg, int id ) {
    if( pointerp(arg) )
        return arg;

    if( arg-- <= 0 ) {
        if( ENV(them)->query_underwater() )
            tell_object( them, "You cannot breathe the water any more!\n");
        else
            tell_object( them, "The air suddenly feels a lot heavier.\n");
        return REMOVE_THIS_EFFECT;
    }

    return arg;

} /* mixed_effect_heart_beat() */

/** @ignore yes */
mixed beginning( object them, mixed arg, int id ) {
    if( !pointerp(arg) )
        tell_object( them, "You feel funny.\n");
    return arg;
} /* beginning() */

/** @ignore yes */
mixed merge_effect(object them, mixed arg1, mixed arg2) {
    if( pointerp(arg1) || pointerp(arg2) )
        return ({ });
    return arg1 + arg2;
} /* merge_effect() */

/* This is the potion handling stuff from here down. */
/** @ignore yes */
mixed query_attrs( int *coord ) {
    int total, intens;

    total = distance_within_region( coord );
    intens = total * 3;
    if( intens > 100 )
        intens = 100;
    return ({ 5, 95, ({ }), ({ ({ "bluey green", intens }) }), ({ }),
           ({ ({ "ever so slightly salty", intens }), }) });
} /* query_attrs() */

/** @ignore yes */
void action_drunk( object ob, int *coord, int quantity ) {
    int total, str;

    total = distance_within_region( coord );
    str = total * quantity;
    str = str / 1000;
    TP->add_effect( file_name(TO), str );
    return;
} /* action_drunk() */

/** @ignore yes */
mixed query_coordinate() { return ({ -30, 30 }); }
