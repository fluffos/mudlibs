/*
**File: broom.c
** Many thanks to Nsd for how to use the patrol command
**and to Cyanide for helping me with the creation of multiple
**brooms. Now let's watch this sucker kick ass.
*/

#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;

set("author","shallar");
set("short","magical broom");
    set ("long", @EndText
A broom that has developed two hands and can walk around. It is
carrying buckets of water with it.
EndText
);
set("id",({"broom","creature"}));
set("prevent_summon","1");
set_size(4);
set_name("magical broom");
set("gender","neuter");
set("race","household applicance");

set("undead",0);

set("damage",({8,20}) );
set("base_ac",2);

set("weapon_name","bucket of water");

set_verbs(({"attack","bash","pummel","thump"}));

    set("nat", 1);

    set("chat_chance", 25);

    set ("chat_output", ({
    }) );

    set ("att_chat_output", ({
    }) );

set_level(26);

set ("patrol", ({ "south", "east" }) );

set("wealth",400);
}
void die (){
say(
"The broom finally shatters into a million pieces with your final blow.\n"+
"The buckets fall to the ground, spilling the water they contained.\n");
::die();
return 1;
}
