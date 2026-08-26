#include <mudlib.h>
#include "oerth.h"
inherit MONSTER;

void create()
{
::create();
seteuid(getuid());
set("short", "Small boy");
set("long",@Endtext
This small boy has nothing better to do all day
other then sit around and listen to Madam Serena
ramble on about the future.
Endtext
);
set("id", ({ "small boy", "boy" }));
set_level(99);
set_size(4);
set_name("boy");
set_living_name("boy");
set("gender", "male");
set("race", "human");
set("damage", ({1,4}));
set("weapon_name", "hands");
enable_commands();
set("natt", 1);
}
