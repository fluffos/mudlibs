#include "../defs.h"

inherit GUARD ;

create(){
  ::create() ;
  set("short", "a castle guard") ;
  set("long", @ENDLONG
A member of the castle guard.
ENDLONG
  );
  set("id", ({ "guard", "castle guard" }) );
 set("stat/constitution", 13) ;
  set_level(20 + random(5)) ;
  set_alignment("ln") ;
  if (random(10)<5)
  arm(WEAPONS(shortswd), "sword");
  else arm(WEAPONS(broadswd), "sword");
  set_size( 6);
  set("natt", 1) ;
  wear(ARM(shield), "shield");
  wear(ARM(chainmail), "chainmail");
  wear(ARM(lgloves), "gloves");
  wear(ARM(leggings), "leggings");
  wear(ARM(helmet), "helmet");
  wear(ARM(hlboots), "boots");
  set_skill("Long Blades", 2, "strength") ;
}

