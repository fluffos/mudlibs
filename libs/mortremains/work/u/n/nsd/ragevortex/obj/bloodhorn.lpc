/*
** File: bloodhorn.c
** Author: Ragevortex
** Updated by: Lady Nsd  (july 2000)
*/


#include <mudlib.h>   //This calls all the neat stuff Cy programed

inherit WEAPON;

void create() {
    seteuid(getuid());
    set("author", "ragevortex");
    set("name", "bloodhorn");
    set_weapon_type("axe/hand");
    set("id",({"axe","bloodhorn","hornaxe","horn"}) );
    set("short", "a bloodhorn axe");
    set("long", @EndText
This mystical wepon is feared among the enemies of the minotaurs.
The axe is made out of the horn of a minotaur god of rage and
it secrates blood.
EndText
    );
    set_bonus(5,3,5);
    set("nosecond", 0);
    set_verbs( ({ "slice", "slash", "cut into", "inviserate", "devastate",
      "stain" }) );
    set_verbs2( ({ "slices", "slashes", "cuts into", "inviserates",
      "devastates", "stains" }) );
    set("value", 500);
}
