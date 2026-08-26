/*
** File: merry2.c
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
set("short","Pink Merry Go Round Horse");
    set ("long", @EndText
This is a bright Pink Merry Go Round Horse that has discovered
how to run around the park without the aid of a machine. This horse
still has the pole in its body, though that hasn't slowed it down.
EndText
   );
set("id",({"horse","merry go round horse","pink"}));
set_size(4);
set_name("Pink Horse");
set("race","toy");
set("gender","female");
set("undead",0);
set("base_ac",8);
set("damage",({1,4}));
set("weapon_name","bite");
set_verbs(({"attack","bite at","chew"}));
    set ("chat_chance", 10);
    set ("chat_output", ({
    }) );
    set ("att_chat_output", ({
    }) );
set_level(2);
set("wealth",27);

}
