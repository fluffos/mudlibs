#include <mudlib.h>
#include "oerth.h"
inherit MONSTER;

void create()
{
::create();
seteuid(getuid());
set("short", "Brewery Assistant");
set("long",@Endtext
This haughty elf came originally from Geoff. His
speciality is the expensive Elvin Blossom Wine.
Endtext
);
set("id", ({ "brewer", "assistant" }));
set_level(4);
set_size(5);
set_name("brewer");
set_living_name("brewer");
set("gender", "male");
set("race", "elf");
set("damage", ({1,4}));
set("weapon_name", "hands");
enable_commands();
set("natt", 1);
}
