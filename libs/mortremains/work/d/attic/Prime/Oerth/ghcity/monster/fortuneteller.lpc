#include <mudlib.h>
#include "oerth.h"
inherit MONSTER;

void create()
{
::create();
seteuid(getuid());
set("short", "Madam Serena");
set("long",@Endtext
This old woman sits here all day long,
spewing crap about the future and
everybodies fate.
Endtext
);
set("id", ({ "madam", "madam serena", "serena", "fortuneteller" }));
set_level(8);
set("size", 5);
set_name("serena");
set_living_name("serena");
set("gender", "female");
set("race", "human");
set("damage", ({1,4}));
set("weapon_name", "hands");
enable_commands();
set("natt", 1);
set("chat_chance",10);
set("chat_output", ({
"Madam Serena says: Yes, that's right, I know the future.\n",
"Madam Serena says: I predict, that im going to be killed soon.\n",
}));
set("chat_att_output", ({
"Madam Serena shouts: SEE, I'M NOT A FAKE!\n",
}));
}
