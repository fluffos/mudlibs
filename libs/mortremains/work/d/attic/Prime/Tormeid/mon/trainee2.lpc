// Guard trainees for the training grounds in the castle.
#include "../defs.h"

inherit MONSTER ;

create(){
  ::create() ;
  set("short", "a guard trainee") ;
  set("long", @ENDLONG
This guard is definately a rookie.  He barely knows how to hold his weapon,
much less use it.
ENDLONG
  );
  set("id", ({ "guard", "trainee guard", "trainee" }) );
 set_level(8) ;
  set_alignment("ln") ;
  set_size(6) ;
  arm(WEAPONS(trainee_wep), "trainee weapon") ;
  wear(ARM(chainmail), "chainmail");
  wear(ARM(buckler), "buckler");
  wear(ARM(lgloves), "gloves");
  wear(ARM(helmet), "helmet");
 set_name("Trainee") ;
  wear(ARM(hlboots), "boots");
  set_skill("Long Blades", 1, "strength") ;
  set_skill("Clubbing Weapons", 1, "strength") ;
  set_skill("Short Blades", 1, "strength") ;
  set_skill("Axes", 1, "strength") ;
  set_skill("Staves", 1, "strength") ;
}

