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
        set_weapon_type("quarterstaff");
	set("id", ({ "staff", "staff of magi" }) );
        set("short", "staff of the magi");
	set("long", @LONG
A powerful, magical staff.
LONG
	);
        set("name", "staff of the magi");
   set_verbs( ({ "attack", "swing at", "stab at", "slash at" }) ) ;
	set("value", 4000);
	set("nosecond", 1);
   }
