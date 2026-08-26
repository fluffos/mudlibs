#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

create(){
  ::create();
  set("short", "Lady Vargas") ;
  set("long", @ENDLONG
Lady Vargas is the wife of one of the nobles that reside here in the
castle.
ENDLONG
  );
  set("id", ({ "lady", "vargas", "lady vargas" }) ) ;
 set("gender", "female") ;
  set("race", "human");
 set_name("lady vargas") ;
  credit(random(100)+ 102) ;
  set_level(6) ;
  set_alignment("tn") ;
  set("damage", ({ 1, 4 }) ) ;
  credit(790) ;
  set_size( 5) ;
  set("weapon_name", "fists");
  set_verbs( ({ "swing at", "attack" }) );
  wear(ARM(embroidered_robe), "robe") ;
  wear(ARM(emerald_ring), "ring") ;
}

