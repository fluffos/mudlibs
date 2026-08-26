/*File orcsword.c
Date: 9/97
Author: Morrigu
Purpose: Short sword for orc warrior, kinda cheezy weapon.
other stuff: looks old and dwarven?  */

#include <mudlib.h>
inherit WEAPON;

void create()
{
seteuid(getuid());
set("author", "Morrigu");
set("name", "shortsword");
set_weapon_type("sword/short");
set_material_type("metal/steel");
set("id", ({"sword", "short sword", "shortsword"}));
set("short", "an old shortsword");
set("long", @Traal
This poorly cared for short sword looks very old.  It looks almost
dwarven in manufacture.
Traal
);
set_bonus(0,0,-1);
set("nosecond", 0);
set_verbs(({"poke", "slice", "slash"}));
set_verbs2(({"pokes", "slices", "slashes"}));
}
