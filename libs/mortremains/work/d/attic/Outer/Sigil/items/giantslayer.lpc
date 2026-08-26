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
        set_weapon_type("sword/long");
set("value",   1300);
	set("id", ({ "giant slayer", "sword" }) );
	set("short", "giant slayer");
	set("long", @LONG
This is Darkwood's famous Giant-slaying blade.
LONG
	);
        set("name", "giant slayer");
   set_verbs( ({ "attack", "swing at", "stab at", "slash at" }) ) ;
	set ("hit_func", 1);
   }

   int hit_func(object targ, int damage){

   if (targ->query("race") == "giant" || (targ->query("race") == "half-giant") ) {
   damage = damage*2;
   }
   return damage;
  }
