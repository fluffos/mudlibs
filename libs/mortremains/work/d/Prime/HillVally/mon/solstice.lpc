/*
** File: skeleton.c
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
     set("short", "Solstice Cosmos");
    set ("long", @EndText
This is a skeleton; there is no flesh left on its body.
He looks back at you with hollow eyes.
EndText
   );
    set("id", ({ "skeleton", "monster" }) );
    set_size(6);
    set_name("skeleton") ;
    set("gender", "neuter");
    set("race", "skeleton");
    set("undead", 1);
    set("damage", ({ 1,4 }) );
    set("weapon_name", "claws") ;
    set_verbs( ({ "attack", "claw at", "swing at" }) ) ;
    set("natt", 1);
    set ("chat_chance", 10);
    set ("chat_output", ({
      "The skeleton stares at you through empty sockets.\n",
    }) );
    set ("att_chat_output", ({
      "The skeleton glares at you through empty sockets.\n",
    }) );
    set_level(1);
}
