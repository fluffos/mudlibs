#include <mudlib.h>
#include "oerth.h"
inherit MONSTER;

void create()
{
::create();
seteuid(getuid());
set("short", "Master Brewer");
set("long",@Endtext
This gnome invented the vat system used in breweing
the free cities fine ales and wines. 
Endtext
);
set("id", ({ "brewer", "master" }));
set_level(6);
set_size(5);
set_name("brewer");
set_living_name("brewer");
set("gender", "male");
set("race", "gnome");
set("damage", ({1,4}));
set("weapon_name", "hands");
enable_commands();
set("natt", 1);
}
