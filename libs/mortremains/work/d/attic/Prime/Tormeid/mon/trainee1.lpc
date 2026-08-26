// Guard trainees for the training grounds in the castle.
#include "../defs.h"

inherit MONSTER ;

create(){
  ::create() ;
  set("short", "a guard trainee") ;
  set("long", @ENDLONG
This trainee is obviously a rookie.  He's stronger than most, but
still not quite up to normal guard calliber.
ENDLONG
  );
  set("id", ({ "guard", "trainee guard", "trainee" }) );
  set_level(10 + random(5) ) ;
  set_alignment("ln") ;
  set_size(6) ;
  arm(WEAPONS(trainee_wep), "trainee weapon") ;
  wear(ARM(chainmail), "chainmail");
  wear(ARM(buckler), "buckler");
  wear(ARM(lgloves), "gloves");
  wear(ARM(helmet), "helmet");
  wear(ARM(hlboots), "boots");
  set_skill("Long Blades", 1, "strength") ;
  set_name("Trainee") ;
  set_skill("Clubbing Weapons", 1, "strength") ;
  set_skill("Short Blades", 1, "strength") ;
  set_skill("Axes", 1, "strength") ;
  set_skill("Staves", 1, "strength") ;
}

