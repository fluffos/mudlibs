#include "../defs.h"

inherit GUARD ;

create(){
    ::create() ;
    set("short", "a castle guard") ;
    set("long", @ENDLONG
The guard eyes you stonily as you move through the area.
ENDLONG
    );
    set("id", ({ "guard", "castle guard" }) );
  set("stat/constitution", 12) ;
  set_level(16  + random(5) ) ;
    set_alignment("ln") ;
    if (!random(2)) 
	arm(WEAPONS(longswd), "sword") ;
    else arm(WEAPONS(mace), "mace") ;
    set_size( 6) ;
    wear(ARM(chainmail), "chainmail");
    wear(ARM(medshield), "shield") ;
    wear(ARM(lgloves), "gloves");
    wear(ARM(leggings), "leggings");
    set_skill("Long Blades", 2, "strength") ;
    set_skill("Short Blades", 2, "strength") ;
    wear(ARM(helmet), "helmet");
    wear(ARM(hlboots), "boots");
}

