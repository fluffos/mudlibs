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
	set_bonus(2, 2, 2);
        set_weapon_type("sword/long");
set("value",   1000);
	set("id", ({ "blade", "sword" }) );
	set("short", "wicked blade");
	set("long", @LONG
This is a sharp wicked-looking blade.
LONG
	);
        set("name", "wicked blade");
   set_verbs( ({ "attack", "swing at", "stab at", "slash at" }) ) ;
}
