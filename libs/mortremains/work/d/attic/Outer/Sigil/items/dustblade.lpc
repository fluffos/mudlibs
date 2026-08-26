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
	set_bonus(2);
        set_weapon_type("sword/short");
set("value",   1600);
	set("id", ({ "dust blade", "sword", "blade" }) );
	set("short", "dust blade");
	set("long", @LONG
This is The Blade of Modron Death.
LONG
	);
        set("name", "dust blade");
   set_verbs( ({ "attack", "swing at", "stab at", "slash at" }) ) ;
}
