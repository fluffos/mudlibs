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
	set_bonus(3);
        set_weapon_type("whip");
	set("id", ({ "whip" }) );
	set("short", "whip of flame");
	set("long", @LONG
an abyssal whip of pure fire
LONG
	);
        set("name", "whip of flame");
   set_verbs( ({ "attack", "swing at"}) ) ;
	set("damage_type", "fire");
set("value", 20000); 
set("dest_at_die", 1);
   }

 