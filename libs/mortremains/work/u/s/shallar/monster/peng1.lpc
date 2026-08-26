/*
** File: penq1.c
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
set("short","head penguin waiter");
    set ("long", @EndText
This is the head waiter for this cafe. You notice that he
is a penguin which means that he gets paid in fish and
is always dressed for the ocassioh.
EndText
   );
set("id",({"waiter","penguin"}));
set_size(2);
set_name("Head Waiter");
set("race","animal");
set("gender","male");
set("undead",0);
set("base_ac",7);
set("damage",({1,4}));
set("weapon_name","peck");
set_verbs(({"attack","peck"}));
    set ("chat_chance", 10);
    set ("chat_output", ({
    }) );
    set ("att_chat_output", ({
    }) );
set_level(4);
set("wealth",44);

}
