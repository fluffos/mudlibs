#include <mudlib.h>

inherit MONSTER;

create(){
  ::create();
  set("short", "a chicken");
  set("long", "This is a little white chicken.\n");
  set("id", ({ "#CHICKEN#", "#BLAH#", "chicken" }) );
  set("race", "chicken");
  set_hide_race(); 
  set_name("chicken");
  set_level(1);
  set_alignment(1);
  set("damage", ({ 1, 3 }) );
  set("weapon_name", "beak");
  set("chat_chance", 2);
  set("chat_output", ({
    "The chicken clucks at you.\n",
    "The chicken scratches at the ground.\n",
    "The chicken preens its feathers.\n",
  }) );
  credit(random(30)) ;
  set("att_chat_output", ({ 
     "Feathers fly everywhere around you!\n",
  }) );
  set_verbs( ({ "peck at", "jab at", "fly at", "attack" }) );
  set_verbs2(({ "pecks at", "jabs at", "flies at", "attacks" }) );
}
