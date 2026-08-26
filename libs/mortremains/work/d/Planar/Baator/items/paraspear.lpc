/*
** FILE: obsword.c
** PURPOSE: Example of set_bonus() function.
** CREATOR: Cyanide@Nightfall's Keep
** CHANGES:
**    9 Apr 97    Cyanide    Created the file.
**   18 Jun 97    Cyanide    Updated the weapon to include the new
**                           set_weapon_type function.
*/

#include <mudlib.h>

inherit WEAPON;

void create() {
    set_bonus(3);
    set_weapon_type("spear");
    set("id", ({ "spear" }) );
    set("short", "chilling spear");
    set("long", @LONG
A demonic weapon of the nine hells
LONG
    );
    set("name", "chilling spear");
    set_verbs( ({ "attack", "swing at", "stab at", "slash at" }) ) ;
    set("hit_func", 1);
    set("value", 2600); 
}

int hit_func(object targ, int damage){

    if (!random(25)) {
	tell_object(targ, "The spear stuns you!\n");
	targ->black_attack(random(2) + 1);
    }

    return damage;
}


