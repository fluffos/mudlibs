#include <mudlib.h>
inherit MONSTER;

void create()
{
::create();
seteuid(getuid());
set("short", "A brawler");
set("long", @Endtext
This is one of the patrons of the inn who gathers here every
night for some cards and some ale. You seem to have disturbed
his game and he is not happy.
Endtext
);
set("id", ({"mat", "brawler", "patron"}));
set_level(5);
set_size(5);
set_name("Mat");
set_living_name("Mat");
set("gender", "male");
set("race", "human");
set("weapon_name", "fists");
set("damage", ({3,8}));
set("aggressive", 5);
set_verbs(({"smack", "punch", "hit"}));
set_verbs2(({"smacks", "punches", "hits"}));
enable_commands();
set("wealth", 100+(random(1000)));
set("chat_chance", 10);
set("att_chat_output", ({
"Brawler screams: That was the best hand I had all night. You will pay for that one!\n",
"Brawler screams: I will crush you for ruining our game!\n",
}));
}
