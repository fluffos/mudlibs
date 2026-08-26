#include <mudlib.h>
inherit MONSTER;

void create()
{
::create();
seteuid(getuid());
set("short", "A bartender");
set("long", @Endtext
He is a short, stout looking man who seems to enjoy what he does
for a living. He tends his bar and takes care of his inn, and 
makes sure that none of his patrons causes too much trouble. He 
sure is one happy man though.
Endtext
);
set("id", ({"bartender", "innkeeper", "anheg"}));
set_level(8);
set_size(5);
set_name("Anheg");
set_living_name("Anheg");
set("gender", "male");
set("race", "human");
set("damage", ({5,10}));
set("weapon_name", "fists");
set_verbs(({"smack", "punch", "hit", "uppercut"}));
set_verbs2(({"smacks", "punches", "hits", "uppercuts"}));
enable_commands();
set("wealth", 200+(random(300)));
set("chat_chance", 10);
set("chat_output", ({
"Anheg says: What's ya poison my good traveler?\n",
"Anheg says: Step up to the bar my good friend and drown ya sorrows in a fresh pint.\n",
"Anheg says: I once served the High Dragon himself in here. Man could he drain a tankard.\n",
}));
set("att_chat_output", ({
"Anheg yells: You drunken scum, I will toss you out on your arse for this.\n",
"Anheg yells: Some people just have no honor. Ya feed them drink and then ya try to kick ya arse. I will show them.\n",
"Anheg yells: That's it. You are cut off my friend. I think it is time for you to leave.\n",
}));
}
