#include <mudlib.h>

inherit MONSTER;

create(){
    ::create();
    set("short", "a fat pig");
    set("long", "This is a plump oinker.\n");
    set("id", ({ "#OINK#", "#BLAH#", "pig", "soe" }) );
    set("race", "pig");
    set_name("pig");
    set_level(1);
    set_alignment("n");
    set("damage", ({ 1, 3 }) );
    set("weapon_name", "hooves");
    set("chat_chance", 8) ;
    set("chat_output", ({
      "The pig makes some obscene noises.\n",
      "The pig rolls around in the dirt.\n",
      "The pig sniffs you.\n",
      "Pig says: Oink.\n",
      "The pig snorts.\n",
      "The pig looks for food.\n",
    }) );
    credit(query_level() * 20); 
    set("att_chat_output", ({ 
      "The pig oinks angrily!\n",
    }) );
    set_verbs( ({ "kick at", "attack" }) );
}


