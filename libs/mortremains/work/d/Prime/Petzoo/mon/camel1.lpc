#include <mudlib.h>

inherit MONSTER;

create(){
    ::create();
    set("short", "a fat camel");
    set("long", "This is a fat, smelly camel.\n");
    set("id", ({ "#COW#", "#BLAH#", "camel" }) );
    set("race", "camel");
    set_name("camel");
    set_level(2);
    set_alignment("n");
    set("damage", ({ 1, 3 }) );
    set("weapon_name", "teeth");
    set("chat_chance", 8) ;
    set("chat_output", ({
      "The camel looks for some food.\n",
      "You cringe as you get a whiff of the camel.\n",
      "The camel looks at you with a vacant look.\n",
    }) );
    credit(query_level() * 20);
    set("att_chat_output", ({ 
      "The camel looks at you with a vacant look.\n",
    }) );
    set_verbs( ({ "bite at", "attack" }) );
}



