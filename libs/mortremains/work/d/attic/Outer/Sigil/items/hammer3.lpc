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

    set_weapon_type("hammer");
	set_bonus(3);
set("value",   1500);
	set("id", ({ "warhammer", "hammer" }) );
	set("short", "Hammer of doubt");
	set("long", @LONG
This is Factol Terrance's weapon.
LONG
	);
        set("name", "Hammer of doubt");
   set_verbs( ({ "attack", "swing at", "crush", "pound on" }) ) ;
}
