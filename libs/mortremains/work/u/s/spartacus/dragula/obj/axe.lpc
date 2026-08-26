/*
** File: axe.c
** hacked beyond belief by Spartacus, 4-29-00
*/


#include <mudlib.h>   //This calls all the neat stuff Cy programed

inherit WEAPON;

void create() {
    seteuid(getuid());

    set("author", "spartacus");

    set("name", "axe");

    set_weapon_type("axe/hand");

  set_material_type("wood/ironwood");

  set("id", ({  "guitar", "axe", "ibanez",  "destroyer" }) );

    set("short", "an ibanez destroyer");

    set("long",  "This is an Ibanez Destroyer, made out of ironwood.\n"+
"The whole guitar is wood, and it looks like it could double as a killer ''axe''.\n");

    // bonus makes it a magical weapon, 1,2,3,4,5
    // You can also do it like this set_bonus(1,1,1);
    //   The first number makes it a +1 weapon
    //   The second means it has a +1 to hit
    //   The third means it has a +1 to damage
    // In other words it is conceieveable that you could make a weapon
    // that would have a +1 to hit and damage, but not be magical
    // You would do that like this       set_bonus(0,1,1);
  set_bonus(0,1,2);

    set("nosecond", 1);

    set_verbs( ({ "slice", "slash", "cut into" }) );
    set_verbs2( ({ "slices", "slashes", "cuts into" }) );

}
