#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

create(){
  ::create();
  set("short", "a cook") ;
  set("long", @ENDLONG
A cook who is trying to prepare for dinner.
ENDLONG
  );
  set("id", ({ "cook" , "commoner" }) ) ;
  if (random(10)+1 < 5) set("gender", "female") ;
  else set("gender", "male") ;
  set("race", "human");
  set_name("cook") ;
  set_align("ln") ;
 set_level( random(3) + 1) ;
  set("CLASS", "warrior") ;
  set("natt", 1);
  set("damage", ({ 2, 4 }) );
  set_size( 6);
  set("weapon_name", "fists");
  set_verbs( ({ "swing at", "attack" }) );
  set("wealth", random(30) + 12) ;
}

