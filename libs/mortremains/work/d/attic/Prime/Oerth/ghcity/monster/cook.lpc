#include <mudlib.h>
#include "oerth.h"
inherit MONSTER;

void create()
{
::create();
seteuid(getuid());
set("short", "A Cook");
set("long",@Endtext
This guy makes the shit people eat.
Endtext
);
set("id", ({ "cook"}));
set_level(4);
set_size(5);
set_name("cook");
set_living_name("cook");
set("gender", "male");
set("race", "gnome");
set("damage", ({3,8}));
set("weapon_name", "hands");
enable_commands();
set("natt", 1);
}
