/*
** File: peng2.c
** Date: June 2000
** created by Shallar
*/

#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
set ("author","shallar");
set("short","penguin waiter");
    set ("long", @EndText
This is one of the members of the wait staff here. It is a 
penguin whose natural looks always have him ready for work.
For some reason, he likes to dance while bringing drinks.
EndText
   );
set("id",({"waiter","penguin"}));
set_size(2);
set_name("Penguin Waiter");
set("race","animal");
set("gender","male");
set("base_ac",7);
set("undead",0);
set("damage",({1,4}));
set("weapon_name","peck");
set_verbs(({"attack","peck"}));
    set ("chat_chance", 10);
    set ("chat_output", ({
    }) );
    set ("att_chat_output", ({
    }) );
set_level(3);
set("wealth",32);

}
