#include "../defs.h"

inherit GUARD ;

create(){
    ::create() ;
    set("stat", ([ "strength" : 15 + random(4),
      "constitution" : 12 + random(4) + random(5),
      "dexterity" : 10+random(5)+random(5),
    ]) );
    set("short", "a castle guard") ;
    set("long", @ENDLONG
This man bears the insignia of the Castle Guard, and is sworn to protect
the castle with his life, by any means necessary.
ENDLONG
    );
    set("id", ({ "castle guard", "guard" }) ) ;
    set_alignment("ln") ;
    set_size(7) ;
    set("moving", 1) ;
    set_skill("Long Blades", 4, "strength");
    set_skill("Polearms", 3, "strength");
    arm(WEAPONS(royal_weapon), "ROYAL_WEAPON") ;
    wear(ARM(chainmail), "chainmail");
    wear(ARM(lgloves), "gloves");
    wear(ARM(helmet), "helmet");
    wear(ARM(hlboots), "boots");
    set_level(20 + random(12) ) ;
}
