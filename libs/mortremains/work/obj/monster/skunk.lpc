/*
** File: skunk.c
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
    set("short", "a skunk");
    set ("long", @EndText
This is a skunk, it's black with white fur down it's back.
It dosen't smell bad, but if you piss it off, it will.
EndText
    );
    set("id", ({ "skunk", "monster" }) );
    set_size(1);
    set_name("skunk") ;
    set("gender", "neuter");
    set("race", "animal");
    set("damage", ({ 1,4 }) );
    set("weapon_name", "claws") ;
    set_verbs( ({ "attack", "claw at", "swing at" }) ) ;
    set ("chat_chance", 10);
    set ("chat_output", ({
    }) );
    set ("att_chat_output", ({
    }) );
    set_level(1);
    arm("/doc/examples/axe") ;
}
