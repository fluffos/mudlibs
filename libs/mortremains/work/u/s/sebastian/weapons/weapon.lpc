/*
	Add stuff in comments, or die!
*/


#include <mudlib.h>   //This calls all the neat stuff Cy programed

inherit WEAPON;

void create() {
  seteuid(getuid());
   set("author", "nightmask");
   set("name", "axe");
   set_weapon_type("axe/hand");
   set_material_type("metal/silver");
   set("id", ({ "axe", "silver axe" }) );
   set("short", "an axe");
   set("long", "This is a finely crafted silver axe.\n"+
       "The handle is made of wood, but the blades are pure silver.\n");
   set_bonus(1);
   set("nosecond", 0);
   set_verbs( ({ "slice", "slash", "cut into" }) );
   set_verbs2( ({ "slices", "slashes", "cuts into" }) );

}
