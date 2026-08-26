#include <mudlib.h>

inherit WEAPON;

void create() {
    seteuid(getuid());

    set("author", "shya");

    set("name", "frozen axe");

    set_weapon_type("axe/hand");


    set("id", ({ "axe", "frozen axe" }) );

    set("short", "a frozen axe");

    set("long", "This axe is heavy and covered in ice.\n"+
      "The handle is made of wood, but the blades are pure ice.\n");


    set("nosecond", 1);

    set_verbs( ({ "slice", "slash", "cut into" }) );
    set_verbs2( ({ "slices", "slashes", "cuts into" }) );

}
