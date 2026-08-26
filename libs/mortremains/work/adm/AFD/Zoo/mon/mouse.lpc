#include <mudlib.h>

inherit MONSTER;

create(){
  ::create();
  set("short", "a mouse");
  set("long", "It is little mouse.\n");
  set("id", ({ "#meese#", "#BLAH#", "mouse" }) );
  set("race", "rodent");
  set_hide_race(); 
  set_name("mouse");
  set_level(1);
  set_alignment(0);
  set("damage", ({ 1, 3 }) );
  set("weapon_name", "teeth");
  credit(random(30)) ;
  set_verbs( ({ "attack", "bite at" }) );
}
