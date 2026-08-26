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
        set_weapon_type("halberd");
set("value",   5000);
	set("id", ({ "dragonlance", "lance" }) );
	set("short", "dragonlance");
	set("long", @LONG
This is the fabled dragonlance.
It is a footman's lance about 9 feet in length.
LONG
	);
	set("damage", ({ 2, 24 }));
        set("name", "dragonlance");
   set_verbs( ({ "attack", "thrust at", "stab at", "pierce at" }) ) ;
	set ("hit_func", 1);
   }

   int hit_func(object targ, int damage){
	
   if (targ->query("race") == "dragon" || (targ->query("race") == "dracolich") ) {
   damage = (this_player()->query("hit_points"));
   write("The dragonlance glows with righteous wrath!\n");
     
   }
   return damage;
  }
