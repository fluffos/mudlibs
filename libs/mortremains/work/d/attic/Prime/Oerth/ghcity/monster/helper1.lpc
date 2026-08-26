#include <mudlib.h>
#include "oerth.h"
inherit MONSTER;

void create()
{
::create();
seteuid(getuid());
set("short", "Brewery Assistant");
set("long",@Endtext
This dwarf mastered the fine art of drinking ale,
and now strives to master the art of making it.
the free cities fine ales and wines. 
Endtext
);
set("id", ({ "brewer", "assistant" }));
set_level(4);
set_size(5);
set_name("brewer");
set_living_name("brewer");
set("gender", "male");
set("race", "dwarf");
set("damage", ({1,4}));
set("weapon_name", "hands");
enable_commands();
set("natt", 1);
}
