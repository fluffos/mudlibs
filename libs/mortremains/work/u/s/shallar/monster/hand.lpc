/*
**File: hand.c
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
set("short","flying glove");
    set ("long", @EndText
This is a giant blue glove which flies around the area. It has an index
finger pointed at people and wears an evil looking smile across
the rest of the fingers. As it touches things and people, they turn
grey and start to slow down. Maybe you don't want to mess with it.
EndText
   );
set("id",({"glove","hand","flying glove"}));
set_size(6);
set_name("flying glove");
    set("gender", "neuter");
set("race","hand");
set("undead",0);
set("wealth",230);
set("damage",({2,9}));
set("base_ac", 3);
set("weapon_name","pound");
set_verbs(({"attack","tap","nudge"}));
set("stat/strength",15);
set("stat/constitution",19);
    set ("chat_chance", 10);
    set ("chat_output", ({
    }) );
    set ("att_chat_output", ({
    }) );
set_level(12);

}
