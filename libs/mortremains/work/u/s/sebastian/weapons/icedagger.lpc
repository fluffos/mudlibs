/*
	File: icedagger.c
	Date: June 23 1 triple-9
	Purpose: It's a dagger, made from an icicle, kinda obvious
	Other Notes: I'm slowly going albino
*/


#include <mudlib.h>   //This calls all the neat stuff Cy programed

inherit WEAPON;

void create() {
  seteuid(getuid());
	set("author","sebastian");
	set("name", "dagger");
	set_weapon_type("dirk");
	set_material_type("ice");
	set("id", ({"dagger", "ice dagger", "icicle" }));
	set("short", "an ice dagger");
	set("long", @EndText
	This is a dagger, crafted from a single icicle.  It glows with
	moderate power.
EndText
);
	set_bonus(1,2,2);
   set("nosecond", 0);
   set_verbs( ({ "slice", "slash", "cut into" }) );
   set_verbs2( ({ "slices", "slashes", "cuts into" }) );

}
