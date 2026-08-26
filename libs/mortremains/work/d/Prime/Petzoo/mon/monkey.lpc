#include <mudlib.h>

inherit MONSTER;

create(){
    ::create();
    set("short", "a furry little monkey");
    set("long", "This is a cute little monkey.\n");
    set("id", ({ "#MONKEY#", "#BLAH#", "monkey" }) );
    set("race", "monkey");
    set_name("monkey");
    set_level(2);
    set_alignment("cg") ;
    set("damage", ({ 1, 3 }) );
    set("weapon_name", "fists");
    set("chat_chance", 9) ;
    set("chat_output", ({
      "The monkey does something funny.\n",
      "The monkey does a human trick.\n",
      "The monkey picks at his butt.\n",
      "The monkey picks something out of his hair and eats it.\n",
      "The monkey climbs all around.\n",
      "The monkey dances for you.\n",
    }) );
    credit(query_level() * 20); 
    set("att_chat_output", ({ 
      "The monkey chitters at you angrily.\n",
    }) );
    set_verbs( ({ "punch at", "attack", "swing at" }) );
    set_verbs2( ({ "punches at", "attacks", "swings at" }) );
}

