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
    seteuid(getuid());
    set_bonus(3);
    set_weapon_type("sword/short");
    set("id", ({ "sword" }) );
    set("short", "the Sword of Wounding");
    set("long", @LONG
The much feared weapon of Wounding
LONG
    );
    set("name", "Sword of Wounding");
    set_verbs( ({ "attack", "swing at", "stab at", "slash at" }) ) ;
    set("hit_func", 1);
    set("value", 10000);
}

int hit_func(object targ, int damage){

    object wound; 
    seteuid(getuid());  
    write ("Your sword rips gaping wounds!\n");
    tell_object(targ,wrap("You are deeply wounded by the sword!"));
    wound = clone_object ("/d/Ancients/obj/wound_ob") ;
    wound -> set("woundlevel", damage);
    wound -> move (targ) ;

    return damage;
}


