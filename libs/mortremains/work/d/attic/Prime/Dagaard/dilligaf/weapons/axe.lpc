#include <mudlib.h>   //This calls all the neat stuff Cy programed

inherit WEAPON;

void create() {
  seteuid(getuid());
   set("name", "axe");
   set_weapon_type("axe/hand");
   set_material_type("metal/silver");
   set("id", ({ "axe", "silver axe" }) );
   set("short", "an axe");
   set("long", @EndLong
    A crude axe, used by some of the creatures that inhabit Dagaard
    proper, and its surroundings.

EndLong
);
   set_bonus(1);

   set("nosecond", 0);

   set_verbs( ({ "slice", "slash", "cut into" }) );
   set_verbs2( ({ "slices", "slashes", "cuts into" }) );

}
