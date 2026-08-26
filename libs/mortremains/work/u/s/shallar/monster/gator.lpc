/*
** File: gator.c
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
set("short","A Dancing Aligator");
    set ("long", @EndText
This is an aligator which is standing on its back legs. It is prancing
about almost as if it was practicing dance steps, but that's
crazy.
EndText
   );
set("id",({"dancer","gator","aligator"}));
set_size(6);
set_name("aligator");
    set("gender", "neuter");
    set("race", "animal");
set("undead",0);
set("damage",({2,9}));
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
