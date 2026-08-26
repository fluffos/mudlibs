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
	set_bonus(1);
        set_weapon_type("sword/long");
set("value",   500);
	set("id", ({ "flaming sword", "sword" }) );
	set("short", "Flaming sword");
	set("long", @LONG
This is a sword composed of flame.
LONG
	);
        set("name", "Flaming sword");
   set_verbs( ({ "attack", "swing at", "stab at", "slash at" }) ) ;
	set("damage_type", "fire");
   }
