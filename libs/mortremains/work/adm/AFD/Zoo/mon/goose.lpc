#include <mudlib.h>

inherit MONSTER;

create(){
  ::create();
  set("short", "a goose");
  set("long", "It is white goose.\n");
  set("id", ({ "#GOOSE#", "#BLAH#", "goose" }) );
  set("race", "goose");
  set_hide_race(); 
  set_name("goose");
  set_level(1);
  set_alignment(0);
  set("damage", ({ 1, 3 }) );
  set("weapon_name", "beak");
  set_verbs( ({ "attack", "peck at", "bite at" }) );
  credit(random(30)) ;
}
