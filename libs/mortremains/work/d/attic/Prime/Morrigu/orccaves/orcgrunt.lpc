/*Date: 9/97
File: orcg.c
Purpose: Orc grunt for general use in the top level of the cave
Author: Morrigu
Other stuff: I like fur.  */

#include <mudlib.h>
inherit MONSTER;

void create()
{
::create();
seteuid(getuid());
set("short", "an orc grunt");
set("long", @Beeker
This orc seems to be just above the level of "vegetable", and does
not seem too dangerous.
Beeker
);
set("id", ({"orc", "grunt", "orc grunt"}));
set_level(1);
set_size(5);
set_name("an orc grunt");
set_living_name("orc");
set("gender", "male");
set("race", "orc");
set("damage", ({0,3}));
set("weapon_name", "hairy fists");
set_verbs(({"smack", "slap", "punch", "thwap"}));
set_verbs2(({"smacks", "slaps", "punches", "thwaps"}));
set("natt", 1);
}
