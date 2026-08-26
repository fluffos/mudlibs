/*
** File: bmean.c
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
set("short","blue meanie");
    set ("long", @EndText
This is a blue meanie. Its goal is to take the life and fun
out of Pepperland. It has blue fur and blackish hair.
EndText
   );
set("id",({"meanie","blue meanie"}));
set_size(5);
set_name("blue meanie");
set("gender","male");
set("race","cartoon");
set("undead",0);
set("wealth",110);
set("damage",({2,5}));
set("ac",3);
set("weapon_name","bite");
set_verbs(({"attack","chew"}));
set("stat/strength",15);
set("stat/constitution",19);
    set ("chat_chance", 10);
    set ("chat_output", ({
    }) );
    set ("att_chat_output", ({
    }) );
set_level(10);

}
