/*
**File: Mussolini.c
*/

#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    seteuid(getuid());
    enable_commands() ;
    set("author", "nsd");
    set("short", "Mussolini demon");
    set ("long", @EndText
Mussolini is the Italian allied of the NAZI movement. One of
the deadly knights that planned to take over the world
along with Hitler. He's harmful and dangerous.
His expertise is the battles in the deserts.
EndText
    );
    set("id", ({ "Musolini", "musolini", "demon"}) );
    set_size(6);
    set_name("Mussolini demon") ;
    set("gender", "male");
    set("race", "demon");
    set("undead", 1);
    set("damage", ({25, 70}) );
    set("damage_type", "slashing");
    set("weapon_name", "sharp sand crystals");
    set_verbs( ({ "attack", "stab", "swing at", "peer at", "wound"}) ) ;
    set("natt", 2);
    set ("chat_chance", 40);
    set ("chat_output", ({
      "Mussolini gives you a sadistic grin.\n",
      "Mussolini raises his right hand and says: Hail Hitler.\n",
      "Mussolini peers into your soul giving you a sudden chill.\n",
      "Mussolini puts the svastica banner before you and says: Bow or Die.\n",
    }) );
    set ("att_chat_output", ({
      "BITE THE DUST, WIMPY HALF-BREED!!\n",
      "His war skills left you astonished.\n",
      "You're not part of my conquer plan!\n",
      "DIE INFERIOR SCUM!!!!!\n",
    }) );
    set_level(30);

    set("wealth", 1000);
    set("prevent_summon", 1);
}

/* End of File */
