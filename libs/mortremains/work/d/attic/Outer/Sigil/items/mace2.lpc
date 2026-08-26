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
	set("light", 1);
        set_weapon_type("mace");
set("value",   1000);
	set("id", ({ "mace" }) );
	set("short", "A glowing mace");
	set("long", @LONG
The soon to be god , Omott's powerful weapon.
LONG
	);
        set("name", "mace");
   set_verbs( ({ "attack", "swing at", "crush", "pound on" }) ) ;
}
