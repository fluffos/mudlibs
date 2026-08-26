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
        set_weapon_type("mace");
set("value",   2250);
	set("id", ({ "mace of disruption", "mace" }) );
	set("short", "Mace of disruption");
	set("long", @LONG
This is A powerful tool versus evil.
LONG
	);
        set("name", "mace of disruption");
   set_verbs( ({ "attack", "swing at", "stab at", "slash at" }) ) ;
	set ("hit_func", 1);
   }
 int hit_func(object targ, int damage){

   if (targ->query("undead")) {
write("Your mace lashes out against the foul undead!\n");
      damage = damage + 10;
   }
   return damage;
  }