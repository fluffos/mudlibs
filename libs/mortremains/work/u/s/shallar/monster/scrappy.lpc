/*
** File: scrappy.c
** Many thanks to Lady Shya who gave me the idea for this :)
** Date: June 2000
** created by Shallar
*/

#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
set("prevent _summon","1");
set ("author","shallar");
set("short","Scrappy Doo");
    set ("long", @EndText
Scrappy Doo is wandering around the path. He is a tiny little puppy and
is walking towards the noise with a determined look on his face.
EndText
   );
set("id",({"scrappy","puppy","dog"}));
set_size(1);
set_name("Scrappy Doo");
set ("race", "animal");
set("gender","male");
set("undead",0);
set("stat/strength",12);
set("stat/constitution",23);
set("base_ac",7);
set("damage",({1,4}));
set("weapon_name","bite");
set_verbs(({"attack","bite at"}));
set("chat_chance",15);
    set ("chat_output", ({
"Scrappy tells you what a wonderful detective his Uncle Scooby is.\n",
"Scrappy just annoys you. You must fight off the temptation to destroy him.\n",
"Scrappy hops up and down.\n",
    }) );
    set ("att_chat_output", ({
"Scrappy screams: TADADATA TA DA! Puppy Power!\n",
"Scrappy says: Let me at him! I'll splat him.\n",
    }) );
set_level(3);

}
