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
	set_bonus(1, 1, 1);
   	set("weapon_type", "Clubbing Weapons");
   	 set("damage_type", "bludgeoning");
   	  set ("material_type", "metal/steel");
	set ("value", 3000);
	set("size", 15);
    set ("mass",30);
     set ("damage", ({ 7, 35 }) );    
	set("id", ({ "maul of titans", "maul", "maul of the titans" }) );
	set("short", "maul of the titans");
	set("long", @LONG
This is the maul of the titans.
LONG
	);
     set("weapon", 1);   
        set("name", "maul");
   set_verbs( ({ "pound", "swing at", "heft at" }) ) ;
 set("nosecond", 1);
}
