/**
 * This is the effect skelton docs.  This effect
 * has a classification of "shades.sight".
 * <p>
 * Describe the arguments in here.
 * <p>
 * This effect has a shadow associated with it.
 * @classification shades.sight
 * @see help::effects
 */
#include "path.h"
#include <effect.h>

/** @ignore yes */
string query_classification() { return "shades.sight"; }

/** @ignore yes */
string query_shadow_ob() { return SHADOWS +"shades_sight"; }

/** @ignore yes */
void beginning( object player ) {
    tell_object( player, "Your eyes tingle momentarily.\n" );
} /* beginning() */

/** @ignore yes */
void merge_effect( object player ) { return; }

/** @ignore yes */
void end( object player ) {
    tell_object( player, "Everything goes dark, as if you'd blinked, but "+
      "then returns to normal.\n" );
} /* end() */

int test_for_effect( object thing ) {
    if ( !thing )
        return 0;
    return member_array( file_name( this_object() ),
      (string *)thing->query_wear_effects() ) != -1;
} /* test_for_effect() */

void person_removing_item(object item, object player) {
    int* ids;

    if (!player) {
        return ;
    }
    ids = player->effects_matching(query_classification());
    if (sizeof(ids)) {
        player->delete_effect(ids[0]);
    }
} /* person_removing_item() */
