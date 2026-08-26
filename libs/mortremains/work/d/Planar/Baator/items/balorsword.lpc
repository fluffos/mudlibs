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
	set_bonus(5);
        set_weapon_type("sword/long");
	set("id", ({ "sword" }) );
	set("short", "Vorpal sword of lightning");
	set("long", @LONG
The much feared weapon of the balor
LONG
	);
        set("name", "vorpal sword of lightning");

   set_verbs( ({ "attack", "swing at", "stab at", "slash at" }) ) ;
	set("hit_func", 1);
	set("damage_type", "lightning");
//set("prevent_drop", 1);
//set("prevent_get", 1);
//set("prevent_insert", 1);
set("value", 700000); 
set("unwield_func", "unwield_func");
set("dest_at_die", 1);
   }

 int hit_func(object targ, int damage){

 	int size, num;

 	size = targ->query("size");
	if (size > 20) return damage;
	if (size > 9) num = 1;
	if (size > 5) num = 2;
	if (size > 0) num = 3;
	if (random(20)<num){
	write ("Your Vorpal sword severs the head of your opponent!\n");
 tell_object(targ,wrap("You are struck in the neck by a vicious blow!"));
 
      damage = (damage *30);
      }
      return damage;
      }
	

