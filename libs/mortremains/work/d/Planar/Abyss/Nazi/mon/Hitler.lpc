/*
** File: Hitler.c
** Author: Lady Nsd
*/

#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "nsd");
    set("short", "Hitler demon");
    set ("long", @EndText
This is one of the biggest assassins in the history of the world.
He's here for the assassination of millions of Jews. 
He's tough and dangerous. No one has defeated him by now.
EndText
    );
    set("id", ({ "Hitler", "hitler", "demon" }) );
    set_size(6);
    set_name("Hitler demon") ;
    set("gender", "male");
    set("race", "demon");
    set("undead", 1);
    set("lore_type", "demon lore");
    set("damage", ({25, 70}) );
    set("weapon_name", "fireballs") ;
    set_verbs( ({ "attack", "burn at", "swing at", "peer at"}) ) ;
    set("natt", 2);
    set("armor_class", 0);
    set("stat/intelligence", 16);
    set("stat/strength", 20);
    set("stat/constitution", 15);
    set("stat/dexterity", 13);
    set("stat/charisma", 10);
    set("damage_type", "fire");
    set ("chat_chance", 40);
    set ("chat_output", ({
      "Hitler glares at you with hatred in his eyes.\n",
      "Hitler cackles insanely.\n",
      "Hitler eyes you from head to toe and realizes you're not worth his time.\n",
      "Hitler says : Inferior races must die, and you're one!\n",
      "Hitler says : You'll regret coming here...\n",
    }) );
    set ("att_chat_output", ({
      "His hatred intimidates you making you feel like a Jew.\n",
      "I'M GONNA SCREW YOU, JEW!!\n",
      "DIE INFERIOR SCUM!!!!!\n",
      "My land is for the superior race...\n",
    }) );
    set_level(40);
    set("wealth", 5000);
    set("prevent_summon", 1);
}

/* End of File */
