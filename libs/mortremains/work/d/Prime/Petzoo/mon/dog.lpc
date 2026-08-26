#include <mudlib.h>

inherit MONSTER;

create(){
    ::create();
    set("short", "a cute mutt");
    set("long", "It's a mutt.\n");
    set("id", ({ "#DOG", "#BLAH#", "dog", "mutt" }) );
    set("race", "dog");
    set_name("mutt");
    set_level(2);
    set_alignment("n");
    set("damage", ({ 2, 4 }) );
    set("weapon_name", "teeth");
    set_verbs( ({ "bite at", "attack" }) );
    set("chat_chance", 9) ;
    set("chat_output", ({
      "The dog wags it's tail lazily.\n",
      "The dog sits.\n",
      "The dog barks.\n",
    }) ) ;
    credit(query_level() * 20); 
}


