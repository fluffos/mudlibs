#include <mudlib.h>

inherit MONSTER;

create(){
    ::create();
    set("short", "a hyper kitten");
    set("long", "This is a cute little kitten with too much energy.\n");
    set("id", ({ "#kat", "#BLAH#", "kitten", "cat", "kitty" }));
    set("race", "cat");
    set_name("kitten");
    set_level(1);
    set_alignment("n") ;
    set("damage", ({ 1, 3 }) );
    set("weapon_name", "claws");
    set("chat_chance", 10) ;
    set("chat_output", ({
      "The kitten licks its paw.\n",
      "The kitten runs around.\n",
      "The kitten attacks itself.\n",
    }) );
    credit(query_level() * 20); 
    set("att_chat_output", ({ 
      "The kitten hisses.\n",
    }) );
    set_verbs( ({ "tear at", "attack", "claw at", "swipe at" }) );
}

