/**
 * This is the effect skelton docs.  This effect
 * has a classification of "potion.alteration.female".
 * <p>
 * Describe the arguments in here.
 * @classification potion.alteration.female
 * @see help::effects
 */
/*
 * This effect, if the quantity is high enough (>100) turns a male
 * creature into a female
 */

inherit "/std/effects/basic";

#include <effect.h>
#include "path.h"

void create() {
    set_boundaries( ({ 41, 31 }), ({ 80, 70 }) );
} /* create() */

/** @ignore yes */
int query_pass_through( int *coord ) { return 30; }

/** @ignore yes */
mixed query_attrs( int *coord ) {
    int total;

    total = distance_within_region( coord ) * 100 / 50;
    if( total > 100 )
        total = 100;

    return ({ 10, 30,
           ({ }),
           ({ ({"red", total }), ({ "blue", total / 2 }) }),
           ({ ({"kerosene", total / 2 }) }),
           ({ ({"kerosene", total }) })
           });
} /* query_attrs() */

/** @ignore yes */
void action_drunk( mixed ob, int *coord, int quantity ) {
    if( TP->query_gender() != 1 ) {
        write("You feel a warm tingling in your chest and bowels.\n");
        return;
    }

    if( quantity >= 100 )
        TP->add_effect( file_name(TO) );

}  /* action_drunk() */

/* now the player effect stuff */
/** @ignore yes */
string query_classification() { return "potion.alteration.female"; }

/** @ignore yes */
int query_indefinite() { return 1; }

/** @ignore yes */
int beginning( object player ) {
    int original;

    original = player->query_gender();

    if( original == 2 ) {
        tell_object( player, "You feel really weird for a moment, but it "
            "passes quickly.\n");
        player->submit_ee( 0, 0, EE_REMOVE );
        return original;
    }

    tell_object( player, "You feel really wierd!  A disconcerting "
        "tingling sensation emerges from your chest and bowels.  "
        "You are definitely not the man you were.\n");

    player->set_gender(2);
    return original;

} /* beginning() */

/** @ignore yes */
void end( object player, int original ) {
    if( original != 2 ) {
        tell_object( player, "With a fiery burning sensation in your chest "
            "and bowels you return to the gender of your birth.\n");
        player->set_gender(original);
    }
} /* end() */

/** @ignore yes */
void merge_effect() { return 0; }

/** @ignore yes */
int survive_death() { return 1; }
