/*
** File: rat.c
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
set ("short", "a rat creature");
    set ("long", @EndText
This is a stupid rat creature. It works for Klindork and loves to
eat quiche. It stands over 6 feet tall when on its hind legs
and is very dangerous. 
EndText
   );
set("id", ({"rat", "creature"}) );
set_size(6);
set_name("rat creature");
    set("gender", "neuter");
    set("race", "animal");
set("undead",0);
set("damage",({3,9}));
set("damage_type","slashing");
set("ac",4);
set("weapon_name","bite");
set_verbs(({"attack", "bite at", "knaw on"}));
set("stat/strength",14);
    set ("chat_chance", 10);
    set ("chat_output", ({
    }) );
    set ("att_chat_output", ({
    }) );
set_level(14);

}
