#include <mudlib.h>

inherit MONSTER;

create(){
  ::create();
  set("short", "a cute mutt");
  set("long", "It's a mutt.\n");
  set("id", ({ "#DOG", "#BLAH#", "dog", "mutt" }) );
  set("race", "dog");
  set_hide_race(); 
  set_name("mutt");
  set_level(2);
  set_alignment(1);
  set("damage", ({ 2, 4 }) );
  set("weapon_name", "teeth");
  set_verbs( ({ "bite at", "attack" }) );
   credit(random(30)) ;
}
