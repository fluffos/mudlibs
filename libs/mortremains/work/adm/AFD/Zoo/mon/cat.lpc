#include <mudlib.h>

inherit MONSTER;

create(){
  ::create();
  set("short", "an old cat");
  set("long", "This is an older cat that is very lazy.\n");
  set("id", ({ "#BLAH#", "#CAT#", "cat" }) );
  set("race", "cat");
  set_hide_race(); 
  set_name("cat");
  set_level(2);
  set_alignment(5);
  set("damage", ({ 2, 4 }) );
  set("weapon_name", "claws");
  set("chat_chance", 2);
  set("chat_output", ({
     "The cat stretches out.\n",
     "The cat looks at you blankly.\n",
     "The cat licks its paw.\n",
  }) );
  credit(random(30)) ;
  set("att_chat_output", ({ 
    "The cat hisses.\n",
  }) );
  set_verbs( ({ "tear at", "attack", "claw at", "swipe at" }) );
}
