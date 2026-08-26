#include <mudlib.h>   //This calls all the neat stuff Cy programed

inherit WEAPON;

void create() {
    seteuid(getuid());
set("author", "Abyss");
set("name", "rune sword");

set_weapon_type("sword/long");

set_material_type("metal/adamantium");

set("id", ({"sword","rune sword","sword of the damned","blade"}) );

set("short", "Sword of the Damned");

set("long","This is the mythical Sword of the Damned.  This sword is the only one of its kind.\n");

    // bonus makes it a magical weapon, 1,2,3,4,5
    // You can also do it like this set_bonus(1,1,1);
    //   The first number makes it a +1 weapon
    //   The second means it has a +1 to hit
    //   The third means it has a +1 to damage
    // In other words it is conceieveable that you could make a weapon
    // that would have a +1 to hit and damage, but not be magical
    // You would do that like this       set_bonus(0,1,1);
set_bonus(5,5,5);

    // "nosecond" set to 1 makes it a 2 handed weapon, 0 means you can have 
    // another weapon wielded with it
    set("nosecond", 0);

    //verbs are what you see when you attack. They are optional.
    set_verbs( ({ "slice", "slash", "cut into" }) );
    //verbs2 is what the other players in the room see
    set_verbs2( ({ "slices", "slashes", "cuts into" }) );

}
