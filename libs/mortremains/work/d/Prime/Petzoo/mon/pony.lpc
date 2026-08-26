#include <mudlib.h>

inherit MONSTER;

create(){
    ::create();
    set("short", "a cute little pony");
    set("long", "This is a cute little pony.\n");
    set("id", ({ "#PONY#", "#BLAH#", "pony" }) );
    set("race", "horse");
    set_name("pony");
    set_level(3);
    set_alignment("n");
    set("damage", ({ 1, 4 }) );
    set("weapon_name", "hooves");
    set("chat_chance", 7) ;
    set("chat_output", ({
      "The pony clip clops around.\n",
      "The pony looks sickeningly cute.\n",
      "The pony looks restless.\n",
      "The pony winnies.\n",
    }) );
    credit(query_level() * 20); 
    set("att_chat_output", ({ 
      "The pony winnies angrily at you!\n",
    }) );
    set_verbs( ({ "kick at", "attack" }) );
}


