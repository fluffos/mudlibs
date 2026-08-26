#include <mudlib.h>
#include "oerth.h"
inherit MONSTER;

void create()
{
::create();
seteuid(getuid());
set("short", "A Waitress");
set("long",@Endtext
This slut serves the patrons here on a regular 
basis, she never seems to sleep, and people keep coming back.
she also brings them food and ale.
Endtext
);
set("id", ({ "waitress" }));
set_level(2);
set("size", 5);
set_name("waitress");
set_living_name("waitress");
set("wealth", 750);
set("gender", "female");
set("race", "human");
set("damage", ({1,4}));
set("weapon_name", "hands");
enable_commands();
set("natt", 1);
set("chat_chance",10);
set("chat_output", ({
"The waitress winks at you.\n",
"The waitress asks: wanna get a room.\n",
}));
set("chat_att_output", ({
"The waitress screams:Now ya aint getting laid.\n",
}));
}
