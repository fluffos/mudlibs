/*
** File: mudrat3.c
** Date: February 14, 2000
** Purpose: attack in sewer
*/

#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;

    set("author", "Nsd");
    set("short", "sewer rat" );
    set ("long", @EndText
A filthy large rat (like one of those rats from the 
sewers of NYC). It's fur is full of liquid mud, and
is ready to bite anyone.
EndText
    );
    set("id", ({ "sewer rat", "rat" }) );
    set_size(1);
    set_name("sewer rat");
    set("gender", "neuter");
    set("race", "rat");
    set("undead", 0);
    set("lore_type", "animal lore");
    set("damage", ({ 1,5 }) );
    set("damage_type", "slashing");
    set("weapon_name", "fangs");
    set_verbs( ({ "attack", "bite", "swing at" }) );
    set("natt", 1);
    set ("att_chat_output", ({
      "Rat bites you.\n",
    }) );
    set_level(5);

    set("aggressive", 1);
}

/* End of File */
