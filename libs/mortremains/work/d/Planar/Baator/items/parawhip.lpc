/*
** FILE: obsword.c
** PURPOSE: Example of set_bonus() function.
** CREATOR: Cyanide@Nightfall's Keep
** CHANGES:
**    9 Apr 97    Cyanide    Created the file.
**   18 Jun 97    Cyanide    Updated the weapon to include the new
**                           set_weapon_type function.
*/

/* Commented out by Chronos.
#include "/u/c/cyanide/debug.h"
*/
#include <mudlib.h>

inherit WEAPON;

void create() {
    set_bonus(3);
    set_weapon_type("whip");
    set("id", ({ "whip" }) );
    set("short", "barbed whip");
    set("long", @LONG
A demonic weapon of the nine hells
LONG
    );
    set("name", "barbed whip");
    set_verbs( ({ "attack", "swing at", "stab at", "slash at" }) ) ;
    set("hit_func", 1);
    set("dest_at_sell", 1);
    set("value", 700);
}

int hit_func(object targ, int damage){

    if (!random(25)) {
	tell_object(targ, "You are stunned by the whip!\n");
	/* No need for DEBUG anymore, right?  :) -- Chronos.
		DEBUG("Hit func works!\n");
	*/
	targ->block_attack(random(2) + 1);
    }

    return damage;
}


