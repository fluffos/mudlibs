#include <mudlib.h>
#include "oerth.h"
inherit MONSTER;

void create()
{
::create();
seteuid(getuid());
set("short", "Bather");
set("long",@Endtext
A Grey Hawk citizen taking a bath.
Endtext
);
set("id", ({ "bather" }));
set_level(3);
set_size(5);
set_name("bather");
set_living_name("bather");
set("gender", "female");
set("race", "halfling");
set("damage", ({1,4}));
set("weapon_name", "hands");
enable_commands();
set("natt", 1);
}
