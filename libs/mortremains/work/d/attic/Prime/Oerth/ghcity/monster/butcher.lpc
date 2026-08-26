#include <mudlib.h>
#include "oerth.h"
inherit MONSTER;

void create()
{
::create();
seteuid(getuid());
set("short", "The Butcher");
set("long",@Endtext
This short, scrawny dwarf, is the cities butcher.
He is currently covered in blood and other entrails
from the animals he's slaughtered this morning.
Endtext
);
set("id", ({ "dwarf", "butcher"}));
set_level(4);
set_size(4);
set("wealth", 500);
set_name("butcher");
set_living_name("butcher");
set("gender", "male");
set("race", "dwarf");
set("damage", ({3,8}));
set("weapon_name", "hands");
enable_commands();
set("natt", 2);
}
