#include <mudlib.h>

inherit MONSTER;

create(){
  ::create();
  set("short", "a fat cow");
  set("long", "This is a fat, smelly cow.\n");
 set("id", ({ "#COW#", "#BLAH#", "cow" }) );
  set("race", "cow");
  set_hide_race(); 
  set_name("cow");
  set_level(2);
  set_alignment(0);
  set("damage", ({ 1, 3 }) );
  set("weapon_name", "teeth");
  set("chat_chance", 2);
  set("chat_output", ({
    "The cow looks for some food.\n",
    "The cow moos loudly.\n",
    "You cringe as you get a whiff of the cow.\n",
    "The cow whips its tail around lazily.\n",
    "The cow looks at you with a vacant look.\n",
  }) );
  credit(30) ;
  set("att_chat_output", ({ 
     "The cow looks at you with a vacant look.\n",
  }) );
  set_verbs( ({ "bite at", "attack" }) );
}
