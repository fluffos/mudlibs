#include <mudlib.h>
inherit MONSTER;

void create(){
::create();
seteuid(getuid());
set("short", "Citizen");
set("long", @Endtext
This is one of the many citizens that inhabit Duegne. She seems
to be oblivious to all the activity that is going on around here.
While they may not cause any trouble, the citizens don't seem
very talkative either.
Endtext
);
set("id",({"citizen", "elf"}));
set_level(3);
set_size(5);
set("moving",1);
set_name("Amberle");
set_living_name("Amberle");
set("gender", "female");
set("race", "elf");
set("damage", ({2,8}));
set("weapon_name", "fists");
set_verbs(({"punch", "smack", "hit"}));
set_verbs2(({"punches", "smacks", "hits"}));
enable_commands();
set("wealth", 50 + (random(50)));
}
