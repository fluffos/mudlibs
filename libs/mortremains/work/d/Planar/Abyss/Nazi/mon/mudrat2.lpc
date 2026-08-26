/*
** File: mudrat2.c
** Date: February 18, 2000
** Purpose: attack in mudPool 
*/

#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;

    set("author", "Nsd");
    set("short", " ");
    set ("long", @EndText
A filthy large rat (like one of those rats from the 
sewers of NYC). It's fur is full of liquid mud, and
is ready to bite anyone.
EndText
    );
    set("id", ({ "mud rat", "rat" }) );
    set_size(1);
    set_name("mud rat") ;
    set("gender", "neuter");
    set("race", "rat");
    set("undead", 0);
    set("lore_type", "animal lore");
    set("damage", ({ 1,5 }) );
    set("damage_type", "slashing");
    set("weapon_name", "fangs");
    set_verbs( ({ "attack", "bite", "swing at" }) );
    set("natt", 1);
    set ("chat_chance", 40);
    set ("chat_output", ({
      "Rat swims in the pool of mud.\n",
      "Rat looks at you and smells something.\n"
    }) );
    set ("att_chat_output", ({
      "Rat bites you.\n",
    }) );
    set_level(5);
    arm("?");
}

/* End of File */
