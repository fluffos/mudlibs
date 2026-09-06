/* NOTE!!!! NEVER EVER MAKE NEW CODE THAT USES THIS IDIOTIC OBJECT!!! */
/* -+ Doomdark 08-Sep-98 +- */


/* An invisible object placed inside the player sitting on a bench 
   or on a lord_throne or in Fighters' Inn //Frobozz 18.3.1993 */
/* Adds players healing by two (one more than resting) */
/* //Frobozz 26.12.1991 */
// AARGH! Fixed by Graah 30-Jul-96
// AAARGH! 21-Dec-96 / Graah: No heart beat at all. Player's HB
// checks if we are carrying this piece of shit!
/* ARGH! Even worse... If check is done _every_ HB from player ob,
 * instead of having its own HB is actually much much worse. But,
 * this should never be used in any case. Use heal rate boosts.
 * -+ Doomdark +-
 */

#include <conditions.h>
#include <invis_levels.h>
#include <player_defs.h>

inherit "basic/id";

object master;
int x;

void
create()
{
    set_name("heal ob");
    set_short("Heal Object");
    set_invis(IL_TOTALLY_INVISIBLE);
}

init() {
    add_action("quit","quit");
    master=environment(); /* No wiz interference here! */
    //  set_heart_beat(1);
    destruct_other_heal_obs();
}

get() { return 1; }
drop() { return 1; }

destruct_me() {
    destruct(this_object());
    return 1;
}

quit() {
    destruct_me();
    return 0;
}

destruct_other_heal_obs() {
    object *env;
    int i;
    env=all_inventory(environment());
    for(i=sizeof(env)-1;i>=0;i--)
	if(env[i]->id("heal ob") && env[i]!=this_object())
	    env[i]->destruct_me();
}
