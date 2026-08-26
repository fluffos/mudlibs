/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: perception.c,v 1.1 1998/01/06 04:14:00 ceres Exp $
 * $Log: perception.c,v $
 * Revision 1.1  1998/01/06 04:14:00  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "potion.perception".
 * <p>
 * Describe the arguments in here.
 * <p>
 * This effect has a shadow associated with it.
 * @classification potion.perception
 * @see help::effects
 */
#include "path.h"
#include <effect.h>

#define MAX_EFFECT 200
#define MAX_DURATION 120
#define MAX_STRENGTH 240
#define MIN_STRENGTH 20

/** @ignore yes */
string query_classification() { return "potion.perception"; }

/** @ignore yes */
//string query_shadow_ob() { return SHADOWS + "perception"; }
/** @ignore yes */
string query_shadow_ob() { return SHADOWS + "skill_bonus"; }

int diminish(int x, int x_max, int y_max) {
    // Sort of a poor-man's 1-e(-x)
    if (x > x_max) return x_max;
    return (2*x_max - x)*x*y_max/(x_max*x_max);
} /* diminish() */

/** @ignore yes */
mixed beginning( object player, int strength, int id ) {
    int bonus;

    if (strength < MIN_STRENGTH) {
        player->submit_ee( 0, 0, EE_REMOVE);
        return 0;
    }
    player->submit_ee( 0, diminish(strength, MAX_STRENGTH, MAX_DURATION),
                      EE_REMOVE );
    tell_object(player, "A feeling of clearheadedness washes over " +
                "you, and you are suddenly able to perceive the " +
                "tiniest details in the world around you.\n");
    bonus = diminish(strength, MAX_STRENGTH, MAX_EFFECT);
    return (["other.perception":bonus]);
} /* beginning() */

/** @ignore yes */
mixed merge_effect( object player, mixed strength1, int strength2, int id ) {
    int arg, bonus, duration;

    arg = strength2 + player->expected_tt();
    duration = diminish(arg, MAX_STRENGTH, MAX_DURATION);
    player->submit_ee( 0, duration, EE_REMOVE );
    bonus = diminish(arg, MAX_STRENGTH, MAX_EFFECT);
    if (bonus > strength1["other.perception"]) {
        tell_object(player, "You feel your perceptions increase somewhat.\n");
    }
    strength1["other.perception"] = bonus;
    return strength1;
} /* merge_effect() */
 
/** @ignore yes */
void end( object player, int strength, int id ) {
    // I can do this because the strength is normally a mapping...
    if (!intp(strength)) {
        tell_object( player, "Your perceptions return to normal.\n" );
    }
} /* end() */
