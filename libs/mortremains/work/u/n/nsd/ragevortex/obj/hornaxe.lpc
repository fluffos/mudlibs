/*
** File: hornaxe.c
** Author: Ragevortex
** Updated by: Lady Nsd (july 2000)
*/

#include <mudlib.h>

inherit WEAPON;

void create() {
    seteuid(getuid());
    set("author", "Ragevortex");
    set("name", "hornaxe");
    set_weapon_type("axe/hand");
    set_material_type("metal/gold");
    set("id", ({ "axe", "gold axe" }) );
    set("short", "a hornaxe");
    set("long",
      "This is a mystical axe made from the horn of a minotaur hornaxe.\n"+
      "the horn is golden and engraved, the handle is made of wood.\n");
    set_bonus(5,3,5);
    set("nosecond", 0);
    set_verbs( ({ "slice", "slash", "cut into" }) );
    set_verbs2( ({ "slices", "slashes", "cuts into" }) );
    set("value", 800);
}
