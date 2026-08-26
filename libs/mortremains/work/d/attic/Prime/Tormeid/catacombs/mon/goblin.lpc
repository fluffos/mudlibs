#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

create(){
  ::create();
  set("short", "a fat little goblin") ;
  set("long", @ENDLONG
A squat little goblin with a bad complexion.
ENDLONG
  );
  set("id", ({ "goblin" }) ) ;
  set("gender", "male") ;
  set("race", "goblin") ;
  set_name("goblin") ;
  set_align("ne") ;
  set_level(6) ;
  set("CLASS", "warrior") ;
  set("natt", 1) ;
  set("damage", ({ 1, 4 }) ) ;
  set_size(5) ;
  set("weapon_name", "claws") ;
  set_verbs( ({ "swing at", "attack" }) );
  set("wealth", 30 + random(40) ) ;
  set("aggressive", 1 ) ;
}

