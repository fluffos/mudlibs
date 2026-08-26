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
    set_weapon_type("glaive");
    set("id", ({ "glaive" }) );
    set_bonus(2);
    set("short", "saw-toothed glaive");
    set("long", @LONG
A demonic weapon of the nine hells
LONG
    );
    set("name", "saw-toothed glaive");
    set_verbs( ({ "attack", "swing at", "stab at", "slash at" }) ) ;
    set("hit_func", 1);
    set("value", 700); 
    set("nosecond", 1);
}

int hit_func(object targ, int damage){

    object wound; 
    seteuid(getuid());  
    write ("Your glaive rips gaping wounds!\n");
    wound = clone_object ("/d/Ancients/obj/wound_ob") ;
    wound -> set("woundlevel", 2);
    wound -> move (targ) ;

    return damage;
}


