/*File: morsword.c
Purpose: my sword
date 9/97
author: Morrigu
Other comments: Cookies taste good with milk
*/
#include <mudlib.h>
inherit WEAPON;
void create()
{
set("author","Morrigu");
set("name", "sword");
set_weapon_type("sword/long");
set_material_type("metal/mithril");
set("id", ({"sword", "long sword", "mithril sword", "mithril long sword"}));
set("short", "Morrigu's sword");
set("long", @Goober
This is an immensely powerful weapon meant
to be wielded by no mortal.  Should you find
it, please return it to the nearest immortal.
Goober
);
set_bonus(5,5,5);
set("nosecond", 0);
set_verbs(({"strike", "slash", "cut", "stab", "thrust"}));
set_verbs2(({"strikes", "slashes", "cuts", "stabs", "thrusts"}));
set("prevent_get", 1);
set("prevent_instert", 1);
set("prevent_clean", 1);
set("prevent_drop", 1);
}
