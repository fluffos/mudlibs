#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

create(){
  ::create();
  set("short", "a chef") ;
  set("long", @ENDLONG
The head chef in the Castle kitchen.
ENDLONG
  );
  set("id", ({ "chef" , "commoner" }) ) ;
  if (random(10)+1 < 5) set("gender", "female") ;
  else set("gender", "male") ;
  set("race", "human");
  set_name("chef") ;
  set_align("ln") ;
  set_level( 9 ) ;
  set("CLASS", "warrior") ;
  set("natt", 1);
  set("damage", ({ 2, 4 }) );
  set_size( 6);
  set("weapon_name", "fists");
  set_verbs( ({ "swing at", "attack" }) );
  set("wealth", random(30) + 12) ;
  arm(WEP(butcher_knife), "knife") ;
}


