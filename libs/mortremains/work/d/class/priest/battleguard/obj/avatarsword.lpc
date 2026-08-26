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
                set_weapon_type("sword/two-handed");
	set("id", ({ "sword" }) );
        set("short", "two-handed sword");
	set("long", @LONG
a mighty, black two-haded sword of tempus
LONG
	);
        set("name", "two-handed sword");
        set("damage", ({ 9, 42 }));
   set_verbs( ({ "attack", "swing at", "stab at", "slash at" }) ) ;
}
