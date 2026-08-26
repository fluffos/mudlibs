/*File: orcclub.c
Purpose: A wooden club for the orc.
Date 9/97
author: Morrigu
Other stuff: Xena is a babe.*/

#include <mudlib.h>
inherit WEAPON;

void create()
{
seteuid(getuid());
set("author", "Morrigu");
set("name", "club");
set_weapon_type("club");
set_material_type("wood");
set("short", "A rough wooden club");
set("long", @Goober
This rough hewn wooden club looks crude, but effective.
It's probably not much better than bare fists.
Goober
);
set("id", ({"club", "wooden club"}));
set("nosecond", 0);
set_verbs(({"swing", "swat", "bash"}));
set_verbs2(({"swings", "swats", "bashes"}));
}
