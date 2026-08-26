/*
** File: dog.c
** Date: September 10th, 1997
** Purpose: An example of a monster.
*/

#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "nightmask");
    set("short", "a dog");
    set ("long", @EndText
This is a small cute doggy, it's brown.
EndText
    );
    set("id", ({ "dog", "monster" }) );
    set("stat/constitution", 12);
    set_size(1);
    set_name("dog") ;
    set("gender", "neuter");
    set("race", "animal");
    set("undead", 1);
    set("damage", ({ 1,4 }) );
    set("weapon_name", "claws") ;
    set_verbs( ({ "attack", "claw at", "swing at" }) ) ;
    set("natt", 1);
    set ("chat_chance", 10);
    set ("chat_output", ({
    }) );
    set ("att_chat_output", ({
    }) );
    set_level(1);
}
