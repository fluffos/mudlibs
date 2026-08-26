#include "../defs.h"

inherit GUARD ;

create(){
    ::create() ;
    set("short", "the captain of the Guard") ;
    set("long", @ENDLONG
This formidable man looks like one of the most fearsome warriors you have
ever met.  He exudes confidence and power with every stride as he 
surveys his men.  You can see why this man is in charge.
ENDLONG
    );
    set("id", ({ "guard", "guard captain", "captain" }) ) ;
    set_level(45 + random(12) ) ;
    set("natt", 3) ;
    set_alignment("ln") ;
    set("stat/strength", 19) ;
    set("stat/dexterity", 16) ;
    set("stat/constitution", 15) ;
    arm(WEAPONS(bastardswd), "sword") ;
    set_skill("Long Blades", 5, "strength");
    set_size( 7 ) ;
    clone_object(OBJ(guard_captain_key))->move(TO) ;
    wear(ARM(elven_chain) , "chainmail") ;
    wear(ARM(lgloves), "gloves");
    wear(ARM(helmet), "helmet");
    wear(ARM(protring2), "ring") ;
    wear(ARM(hlboots), "boots");
    // redefining the chat output for the guard captain.  He's cooler.
    set("chat_chance", 2) ;
    set("chat_output", ({
      "The captain of the Guard eyes you warily.\n",
      "The captain of the Guard studies you carefully.\n",
    }) ) ;
}

