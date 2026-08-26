#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

create(){
  ::create();
  set("short", "a repulsive troll") ;
  set("long", @ENDLONG
This large ugly green beast is reknown in the multiverse as one of the
most vicious, hideous, dangerous monsters known to roam
about in the darkness of many a dungeon.  Perhaps the most frightening
thing about this monster is its uncanny ability to regenerate quickly,
making it difficult to kill, and even more difficult to keep dead.
ENDLONG
  );
  set("id", ({ "troll" }) ) ;
  set("gender", "male") ;
  set("race", "troll") ;
  set_name("troll") ;
  set_align("ne") ;
  set("time_to_heal", 1) ;
  set_level(20) ;
  set("aggressive", 1) ;
  set("CLASS", "warrior") ;
  set("natt", 2) ;
  set("damage", ({ 4, 8 }) ) ;
  set_size(7) ;
  set("weapon_name", "claws") ;
  set_verbs( ({ "swing at", "attack" }) );
  set("wealth", 300 + random(300) ) ;
}
