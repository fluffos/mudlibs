/*
** File: maggot.c
*/

#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "nsd");
    set("short", "the maggot");
    set ("long", @EndText
A grotesque giant maggot. It's surface is harsh and pale yellow.
It has slimy legs and it's enormously plump. You fear it can
crush you with it's weight...
EndText
    );
    set("id", ({ "maggot", "the maggot" }) );
    set_size(20);
    set_name("maggot");
    set("gender", "neuter");
    set("race", "worm");
    set("undead", 0);
    set("lore_type", "animal lore");
    set("damage", ({15, 35}) );
    set("damage_type", "acid");
    set("weapon_name", "acid slime");
    set_verbs( ({ "swing at", "peer at", "attack", "hit" }) ) ;
    // set("nat", 2);
    set("natt", 2);
    set("armor_class", 3);
    set("weap_resist", 3);
    set("magic_resist", 5);
    set("base_ac", 2);
    set("stat/strength", 20);
    set("stat/intelligence", 24);
    set("chat_chance",5);
    set ("chat_output", ({
      "The maggot stands on it's back legs, making itself taller.\n",
      "The maggot grunts loudly as it looks at you.\n",
    }) );
    set ("att_chat_output", ({
      "The maggot stands on it's back legs, making itself taller.\n",
      "The maggot hits you hard with it's tail, leaving you breathless.\n",
      "The maggot grabs you with it's front legs and almost crushes you.\n",
      "The maggot rubs it's slime on your skin, and it itches...\n",
      "The maggot gives a piercing scream...!!!\n",
    }) );
    set_level(35);
    set("aggressive", 30);
    set("prevent_summon",1);
}

