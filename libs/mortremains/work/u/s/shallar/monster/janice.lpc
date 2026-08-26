/*
** file: janice.c
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
set("short","Janice");
    set ("long", @EndText
Janice plays the guitar also for the bad. She is like, wow man.
EndText
   );
set("id",({"janice","musician"}));
set_size(3);
set_name("janice");
set("race","muppet");
set("gender","female");
set("base_ac",5);
set("undead",0);
set("wealth",90);
set("damage",({2,6}));
set("weapon_name","guitar");
set_verbs(({"attack","pop"}));
set("chat_chance", 15);
    set ("chat_output", ({
"Janice says: Wow, all you need is like, love!\n",
    }) );
    set ("att_chat_output", ({
    }) );
set_level(6);

}
