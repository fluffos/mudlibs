/*
** File: ppeater.c
*/

#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;

set("author","shallar");
set("short","Purple People Eater");
    set ("long", @EndText
This is a one eyed, one horned monster that is flying in the cave.
It is a dark purple and looks like it is very hungry. Haven't you
heard a song about this type of monster before?
EndText
);
set("id",({"monster","eater","people eater","purple people eater"}));
set("prevent_summon","1");
set_size(7);
set_name("purple people eater");
set("gender","male");
set("race","monster");

set("undead",0);

set("damage",({10,22}) );
set("base_ac",0);
set("aggressive",1);
set("stat/constitution",21);

set("weapon_name","horn");

set_verbs(({"attack","slash","gouge","stab"}));
set("damage_type","slashing");


    set("chat_chance", 25);

    set ("chat_output", ({
    }) );

    set ("att_chat_output", ({
    }) );

set_level(38);


set("wealth",900);
}
