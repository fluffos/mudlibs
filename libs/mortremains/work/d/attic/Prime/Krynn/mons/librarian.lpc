#include <mudlib.h>
inherit MONSTER;

void create() {
::create();
seteuid(getuid());
set("short" ,"The head librarian.");
set("long", @Endtext
This is the head librarian. She looks like a crotchety old bag 
who looks like she has seen one to many years in this world. She 
has a leathery face with a very stern look upon it. You might 
not want to cross her path.
Endtext
);
set("id", ({ "librarian" }));
set_level(10);
set_size(5);
set_name(" Helga, the Librarian");
set_living_name(" Helga, the Librarian");
set("race", "human");
set("damage", ({ 4,10 }));
set("weapon_name", "Mien Kampf");
set_verbs(({"smack" , "thwap"}));
set_verbs2(({"smacks" , "thwaps"}));
enable_commands();
set("wealth", 450);
set("natt", 1);
set("chat_chance", 10);
set("chat_output", ({
"Librarian says: Keep quiet or I will toss your arse outta here.\n",
}));
set("att_chat_output", ({
"Librarian screams: Get out of my library you ignorant heathen!!\n",
}));
}
