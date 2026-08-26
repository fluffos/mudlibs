/*
**File: Franco.c
*/

#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;

    set("author", "nsd");
    set("short", "Franco demon");
    set ("long", @EndText
Franco is an allied for the NAZI movement. He was working for
Hitler from Spain. This is one of the responsible leaders
for the death of millions. His conscience was easily
bought with diamonds and money. He's strong, and hard to kill.
EndText
    );
    set("id", ({ "Franco", "franco", "demon" }) );
    set_size(6);
    set_name("Franco demon") ;
    set("gender", "male");
    set("race", "demon");
    set("undead", 1);
    set("lore_type", "demon lore");
    set("damage", ({25, 70}) );
    set("damage_type", "slashing");
    set("weapon_name", "stab in the back");
    set_verbs( ({ "attack", "burn at", "swing at", "peer at"}) ) ;
    set("natt", 2);
    set ("chat_chance", 40);
    set ("chat_output", ({
      "Franco paces the room watching you.\n",
      "Franco says : Do you have some diamonds for me?\n",
      "Franco says : I can be allied to you for a considerable price.\n",
      "Franco says : Oh Hitler, your money means a lot to me...\n",
      "Franco is worst than a rat. He's a traitor!!!!\n",
    }) );
    set ("att_chat_output", ({
      "BITE THE DUST, WIMPY HALF-BREED!!\n",
      "His war skills left you astonished.\n",
      "Viva la raza superior!!\n",
      "DIE INFERIOR SCUM!!!!!\n",
    }) );
    set_level(30);

    set("wealth", 1000);
    set("prevent_summon",1);
}

/* End of File */
