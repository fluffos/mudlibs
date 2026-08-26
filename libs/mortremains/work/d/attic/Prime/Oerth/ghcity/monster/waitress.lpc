#include <mudlib.h>
#include "oerth.h"
inherit MONSTER;

void create()
{
::create();
seteuid(getuid());
set("short", "A Waitress");
set("long",@Endtext
This tall slender elvin woman is a sight for
sore eyes. She seems very fragile.
Endtext
);
set("id", ({ "waitress" }));
set_level(2);
set("size", 5);
set_name("waitress");
set_living_name("waitress");
set("gender", "female");
set("race", "elf");
set("damage", ({1,4}));
set("weapon_name", "hands");
set_verbs(({"kick", "punch", "elbow", "headbutt"}));
set_verbs2(({"kicks", "punches", "elbows", "headbutts"}));
enable_commands();
set("natt", 1);
set("chat_chance",10);
set("chat_output", ({
"The waitress waits for you to take a seat.\n",
"The waitress welcomes you to the Brass Dragon Inn.\n",
}));
set("chat_att_output", ({
"The waitress begs you for her life.\n",
}));
}
