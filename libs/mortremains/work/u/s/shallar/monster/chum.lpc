/*
**File: chum.c
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
    set("short","Chumley the Walrus");
    set ("long", @EndText
Chumley is standing here, admiring his artwork. He is a walrus that
likes to wear a tie and a hat. He appears to be quite stupid.
EndText
    );
    set("id",({"walrus","chumley"}));
    set_size(6);
    set_name("chumley the walrus");
    set("gender","male");
    set("race","walrus");
    set("undead",0);
    set("base_ac",6);
    set("damage",({2,9}));
    set("weapon_name","tusks");
    set_verbs(({"attack","stab","chomp"}));
    set ("chat_chance", 10);
    set ("chat_output", ({
      "Chumley looks closely at you and asks if you know his friend, Mr. Whoopie.\n",
      "Chumley absently chews on a crayon with a stupid grin on his face.\n",
      "Chumley thinks that lower level characters should play with the horses.\n",
      "Chumley waddles around the entrance looking for Tennessee.\n",
    }) );
    set ("att_chat_output", ({
    }) );
    set_level(12);
    set("wealth",130);

}
