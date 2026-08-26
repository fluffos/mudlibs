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
                set_weapon_type("sword/long");
	set_material_type("metal/green steel");
	set("id", ({ "sword", "green sword" }) );
        set("short", "a green steel longsword");
	set("long", @LONG
This is a well forged weapon.
LONG
	);
        set("name", "green steel longsword");
   set_verbs( ({ "attack", "swing at", "stab at", "slash at" }) ) ;
}
