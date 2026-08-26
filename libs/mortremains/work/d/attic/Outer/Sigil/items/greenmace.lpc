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
                set_weapon_type("mace");
	set_material_type("metal/green steel");
	set("id", ({ "mace", "green mace" }) );
  set("short", "a green steel mace") ;
	set("long", @LONG
This is a well forged weapon.
LONG
	);
        set("name", "Green steel mace");
   set_verbs( ({ "attack", "pound on", "stab at", "crush" }) ) ;
}
