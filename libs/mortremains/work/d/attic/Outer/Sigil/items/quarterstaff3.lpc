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
        set_weapon_type("quarterstaff");
	set("id", ({ "quarterstaff", "staff" }) );
	set("short", "A magical quarterstaff");
	set("long", @LONG
This is An enchanted Staff.
LONG
	);
        set("name", "enchanted staff");
   set_verbs( ({ "attack", "swing at", "poke at", "pound on" }) ) ;
   set("value", 1500);
}
