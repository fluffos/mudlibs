/*
File: cdragon.c
Date: 9/97
Author: Morrigu
Purpose: Dragon template for metamorph
*/
#include <mudlib.h>
inherit MONSTER;
void create()
{
::create();
seteuid(getuid());
set("short", "a red dragon");
set("long", @Glop
This thing is HUGE!  The dragon towers over you,
looking fierce and deadly.  It peers down on you
with eyes as large as your head.
Glop
);
set("id", ({"dragon"}));
set_level(30);
set_size(50);
set_name("a dragon");
set_living_name("a dragon");
set("gender", "female");
set("race", "dragon");
set("damage", ({3,12}));
set("weapon_name", "huge claws");
set("natt", 4);
set_verbs(({"swipe at", "strike at", "claw at"}));
set_verbs2(({"swipes at", "strikes at", "claws at"}));
}
