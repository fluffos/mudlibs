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
   set("weap_type_set", "scythe");

   set ("material_type", "metal/steel");
set("value", 45000);
  set ("mass", 10);
  set ("size", 5);
set("damage_type", "slashing");
  set("weapon", 1);
  set("damage", ({2, 12}));
  set("nosecond", 1);
  set("weapon_type", "Polearms");      
	set("id", ({ "scythe", "deathscythe" }) );
	set("short", "the death scythe");
	set("long", @LONG
A palatable aura of evil surrounds the weapon
LONG
	);
        set("name", "death scythe");
        	set ("hit_func", 1);
   set_verbs( ({ "attack", "swing at", "stab at", "slash at" }) ) ;

   }
 int hit_func(object targ, int damage){

   if (!targ->save_throw()){ 
targ->receive_damage((random(20)+81), "necromancy");
targ->set("last_attacker", this_player());
write("The scythe draws the life from "+targ->query("cap_name")+".\n");

   }
   return damage;
  }
