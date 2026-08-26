/*
**File: Hirohito.c
*/

#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;

    set("author", "nsd");
    set("short", "Hirohito demon");
    set ("long", @EndText
Hirohito was considered a god in Japan, till the day LITTLE BOY
and FAT MAN (nuclear bombs) were dropped in Hiroshima and 
Nagasaki. Then for the first time, his people heard his voice
calling for surrender. Hirohito was part of the deadly knights
from the NAZI movement. He's strong and harmful.
EndText
    );
    set("id", ({ "Hirohito", "hirohito", "demon"}) );
    set_size(6);
    set_name("Hirohito demon") ;
    set("gender", "male");
    set("race", "demon");
    set("undead", 1);
    set("lore_type", "demon lore");
    set("damage", ({25, 70}) );
    set("damage_type", "necromancy");
    set("weapon_name", "radiation");
    set_verbs( ({ "attack", "burn at", "swing at", "peer at"}) ) ;
    set("natt", 2);
    set ("chat_chance", 40);
    set ("chat_output", ({
      "Hirohito says: I'm sorry for your burns, my child!\n",
      "Hirohito gives you a look of compassion\n",
      "Hirohito says: Damn yankee, look what you did to my people!\n",
      "Hirohito bursts into tears burning your soul with every drop.\n",
      "Hirohito worships the swastika and forces you to do the same.\n",
    }) );
    set ("att_chat_output", ({
      "I commanded the bombing of Pearl Harbor, MUHAHAHAHA...\n",
      "HOW DARE YOU EYE ME? I'M A GOD!!!\n",
      "You'll pay for the suffering of my people, Yank!\n",
      "DIE BY MY HAND!!!\n",
    }) );
    set_level(30);

    set("wealth", 1000);
    set("prevent_summon", 1);
}

/* End of File */
