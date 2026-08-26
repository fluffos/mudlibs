#include <mudlib.h>
#include "oerth.h"
inherit MONSTER;

void create()
{
::create();
seteuid(getuid());
set("short", "Brewery Assistant");
set("long",@Endtext
This small little halfling would love to learn
something here. But the brewery master has him
sweeping the floors and cleaning the vats.
Endtext
);
set("id", ({ "brewer", "assistant" }));
set_level(3);
set_size(3);
set_name("brewer");
set_living_name("brewer");
set("gender", "male");
set("race", "halfling");
set("damage", ({1,4}));
set("weapon_name", "hands");
enable_commands();
set("natt", 1);
}
