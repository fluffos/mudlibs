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
	set_bonus(5);
        set_weapon_type("sword/two-handed");
set("value",   5000);
	set("id", ({ "flaming sword", "sword" }) );
	set("short", "Huge Flaming sword");
	set("long", @LONG
This is a Huge sword composed of flame.
LONG
	);
	set("nosecond", 1);
        set("name", "Flaming sword");
        set("size", 11);
   set_verbs( ({ "attack", "swing at", "stab at", "slash at" }) ) ;
	set("damage_type", "fire");
   }
