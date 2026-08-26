#include <mudlib.h>

inherit MONSTER;

create(){
  ::create();
  set("short", "a fat pig");
  set("long", "This is a plump oinker.\n");
  set("id", ({ "#OINK#", "#BLAH#", "pig", "soe" }) );
  set("race", "pig");
  set_hide_race(); 
  set_name("pig");
  set_level(1);
  set_alignment(1);
  set("damage", ({ 1, 3 }) );
  set("weapon_name", "hooves");
  set("chat_chance", 2);
  set("chat_output", ({
    "The pig makes some obscene noises.\n",
    "The pig rolls around in the dirt.\n",
    "The pig sniffs you.\n",
    "The pig looks for food.\n",
  }) );
  credit(random(60)) ;
  set("att_chat_output", ({ 
     "The pig oinks angrily!\n",
  }) );
  set_verbs( ({ "kick at", "attack" }) );
}
