// Ilz coded, Cy cleaned.

#include <mudlib.h>
#include "defs.h"
inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Factol Ambar Vergrove") ;
    set ("long", "The Factol of the Believers of the Source.\n") ;
    set ("id", ({ "factol", "ambar", "vergrove"}) );
    set_name ("ambar") ;
    set ("gender", "male") ;
    enable_commands() ;
    set_living_name("ambar") ;
    set ("stat/constitution", 16);
    set ("stat/strength", 18);
    set ("stat/charisma", 17);
    set ("stat/intelligence", 13);
    set ("stat/dexterity", 18);
    set ("stat/wisdom", 18);
    set("natt", 1);
    set ("thac0", 2);
    set ("damage", ({ 1,4 }) ) ;
    set ("weapon_name", "fists") ;
    set ("CLASS", "warrior");
    set_skill("Long Blades", 5, "Strength") ;
    set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
    arm(OBJ(sword2), "sword") ;
    wear(OBJ(ring4), "ring") ;
    wear(OBJ(displacercloak), "cloak") ;
    wear(OBJ(telepathycrown), "crown") ;
    set_level(19);
}

/* EOF */
