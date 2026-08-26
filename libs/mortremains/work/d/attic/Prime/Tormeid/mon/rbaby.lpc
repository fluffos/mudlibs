#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

create(){
  ::create();
  set("short", "a harmless little baby") ;
  set("long", @ENDLONG
A very cute, very small baby.
ENDLONG
  );
  set("id", ({ "baby" }) ) ;
  set("gender", "male" ) ;
  set("race", "human");
  set_name("baby") ;
  set_align("ln") ;
  set_level(1) ;
  set("CLASS", "warrior") ;
  set("natt", 1);
  set("max_hp", 4) ;
  set("hit_points", 4) ;
  set("damage", ({ 1, 2 }) ) ;
  set_size( 6);
  set("weapon_name", "fists");
  set("smell", "The baby smells like shit.");
  set_verbs( ({ "swing at", "attack" }) );
   set("chat_chance", 5) ;
   set("chat_output", ({
   "The baby cries.\n",
  "The baby wets itself.\n",
  "The baby crawls around.\n",
  "Baby says: GOO GOO!!\n",
  "Baby giggles.\n",
  "Baby drools on itself.\n",
  "Baby shits on itself.\n",
   "The baby sits up and laughs.\n",
  "The baby crawls around the room.\n",
  "The baby crawls around the room.\n",
  "The baby falls on its face and cries.\n",
  }) ) ;
  set("att_chat_output", ({
  "The baby cries!\n",
  }) ) ;
}

int execute_attack(int hit_mod, int dam_mod) { return 0 ; }
