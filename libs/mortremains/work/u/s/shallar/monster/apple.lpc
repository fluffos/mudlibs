/*
** File: apple.c
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
set("short","apple bonker");
    set ("long", @EndText
This is a tall man dressed in a blue suit. He has on a tall top hat
and long tails. He stands over 8 feet tall and is very skinny.  He is part
of th army of the Blue Meanies.
EndText
   );
set("id",({"bonker","man","apple bonker"}));
set_size(9);
set_name("apple bonker");
set("gender","male");
set("race","cartoon");
set("undead",0);
set("wealth",124);
set("damage",({2,11}));
set("ac",3);
set("weapon_name","apple");
set_verbs(({"attack","bonk","pound"}));
set("stat/strength",15);
set("stat/constitution",19);
    set ("chat_chance", 10);
    set ("chat_output", ({
    }) );
    set ("att_chat_output", ({
    }) );
set_level (11);

}
