#include <mudlib.h>

inherit MONSTER;

create(){
  ::create();
  set("short", "a duck");
  set("long", "It is a cute little duck.\n");
  set("id", ({ "#duck#", "#BLAH#", "duck" }) );
  set("race", "duck");
  set_hide_race(); 
  set_name("duck");
  set_level(1);
  set_alignment(0);
 credit(random(30)) ;
  set("damage", ({ 1, 3 }) );
  set("weapon_name", "beak");
  set_verbs( ({ "attack", "bite at", "peck at" }) );
  set("chat_chance", 5) ;
  set("chat_output", ({
   "The duck quacks loudly.\n",
   "The duck quacks at you.\n",
  "The duck waddles about.\n",
  }) );
}
