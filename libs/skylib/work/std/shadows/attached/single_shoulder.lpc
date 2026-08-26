/*
 * $Locker:  $
 * $Id: single_shoulder.c,v 1.3 2000/05/08 03:56:57 pinkfish Exp $
 * $Log: single_shoulder.c,v $
 * Revision 1.3  2000/05/08 03:56:57  pinkfish
 * Fix up a problem caused by adding in the object as the arg to
 * wear effects.
 *
 * Revision 1.2  1998/09/30 09:37:00  pinkfish
 * Changed to handle only satchels and backpacks as possible things for
 * increasing the dexterity handicap.
 *
 * Revision 1.1  1998/01/06 04:35:11  ceres
 * Initial revision
 *
*/
#include "path.h"

inherit "/std/effect_shadow";

/**
 * @ignore yes
 * This method makes sure that we are opnly picking up backpacks and
 * satchels etc.
 * @return true if they are a satchel
 */
private int test_sash( object thing ) {
    return thing->query_type() == "sash" && sizeof( thing->query_pockets() );
} /* test_sash() */

/**
 * @ignore yes
 * This method checks to make sure the item has the effect on it.
 */
private int test_for_effect( object thing ) {
    return member_array( EFFECTS +"single_shoulder",
        (string *)thing->query_wear_effects() ) != -1;
} /* test_for_effect() */

/**
 * @ignore yes
 * This method checks the current handicap and sets it up nicely to
 * the correct value.
 */
void check_handicap() {
    mixed old_arg;
    int new_arg;
    object *things;

    things = (object *)player->query_wearing() - ({ 0 });

    if( objectp( old_arg = arg() ) )
        old_arg = 0;

    new_arg = sizeof( filter( things, (: test_sash :), TO ) ) *
              sizeof( filter( things, (: test_for_effect :), TO ) );

    if( !new_arg ) {
        remove_this_effect();
        return;
    }

    new_arg /= 2;

    if( old_arg == new_arg )
        return;

    player->adjust_bonus_dex( old_arg - new_arg );
    set_arg( new_arg );

} /* check_handicap() */

/** @ignore yes */
void now_worn( object thing ) {
    player->now_worn( thing );
    if( find_call_out("check_handicap") == -1 )
        call_out("check_handicap", 0 );
} /* now_worn() */

/** @ignore yes */
void now_removed( object thing ) {
    player->now_removed( thing );
    if( find_call_out("check_handicap") == -1 )
        call_out("check_handicap", 0 );
} /* now_removed() */
