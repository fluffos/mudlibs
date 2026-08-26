/*
** File: goldthunda.c
** Author: Ragevortex
** Updated by: Lady Nsd (july 2000)
*/

#include <mudlib.h>

inherit WEAPON;

void create() {
    seteuid(getuid());
    set("author", "Ragevortex");
    set("name", "goldthunda");
    set_weapon_type("axe/hand");
    set_material_type("metal/gold");
    set("id", ({ "axe", "gold axe", "goldthunda", "thunda"}) );
    set("short", "The Goldthunda");
    set("long",
      "This is a mystical axe made from the horn of a minotaur hornaxe.\n"+
      "the horn is golden and engraved, the handle is made of wood.\n");
    set_bonus(5,5,10);
    set("nosecond", 0);
    set_verbs( ({ "stab", "electrocute", "inviserate", "smithe", "cut into",
      "anihilate" }) );
    set_verbs2( ({ "stabs", "electrocutes", "inviserates", "smithes",
      "cuts into", "anihilates"}) );
    set("value", 5000);
}
