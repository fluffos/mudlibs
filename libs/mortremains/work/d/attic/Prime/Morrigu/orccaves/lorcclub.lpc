/*File: lorcclub.c
Date: 9/97
Purpose: Large orc club for orc chieftain
Author: Morrigu
Other stuff: This is gonna be cheezy  */

#include <mudlib.h>
inherit WEAPON;

void create()
{
seteuid(getuid());
set("author", "Morrigu");
set("name", "large club");
set_weapon_type("club");
set_material_type("wood");
set("id", ({"club", "large club", "wood club", "large wood club"}));
set("short", "a large wood club");
set("long", @Dipstick
This is a large wood club with small spikes set in it.  It looks like
it could do some real damage.
Dipstick
);
set_bonus(0,0,1);
set("nosecond", 1);
set_verbs(({"swing", "swat", "smack", "thud"}));
set_verbs2(({"swings", "swats", "smacks", "thuds"}));
set("damage", ({1,6}));
}
