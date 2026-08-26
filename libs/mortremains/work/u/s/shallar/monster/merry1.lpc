/*
** File: merry1.c
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
set("short","Blue Merry Go Round Horse");
    set ("long", @EndText
This is a bright Blue Merry Go Round Horse that has discovered
how to run around the park without the need of a machine. The 
horse still has a pole running through it's body.
EndText
   );
set("id",({"horse","merry go round horse","blue"}));
set_size(4);
set_name("Blue Horse");
set("race","toy");
set("gender","male");
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
set("wealth",23);

}
