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
	set_bonus(4);
        set_weapon_type("mace");
	set("id", ({ "crystal mace", "mace" }) );
	set("short", "crystal mace.");
	set("long", @LONG
A positively glowing crystal mace.\n
LONG
	);
	set("value", 3500);
	set("light", 1);
        set("name", "crystal mace");
	set("damage_type", "force");
   set_verbs( ({ "attack", "swing at", "stab at", "slash at" }) ) ;
}
