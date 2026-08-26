/*
**File: animal.c
** Date: June 2000
** created by Shallar
*/

#include <mudlib.h>

inherit MONSTER ;
object sticks;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("prevent_summon",1);
    enable_commands();

    set ("author","shallar");
    set("short","Animal");
    set ("long", @EndText
Animal is the drummer. It looks crazy and unpredictable... in other
words a perfect person to have on the drums. He is chained to the stage.
EndText
    );
    set("id",({"animal","drummer"}));
    set_size(3);
    set_name("animal");
    set("race","muppet");
    set("gender","male");
    set("undead",0);
set("base_ac",5);
set("damage",({2,7}));
    set("weapon_name","sticks");
    set_verbs(({"attack","rattle"}));
    set ("chat_chance", 10);
    set ("chat_output", ({
"Animal looks around and screams: Blue Mean Ies! Blue Mean Ies!\n",
    }) );
    set ("att_chat_output", ({
    }) );
    set_level(8);
}
