
//recoded by Chronos to be more efficient and less clunky. :D
// Yeah, Ilz's too
// Cyanide cleaned a bit, too.

#include <mudlib.h>
#include "defs.h"
inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
	set ("short", "Adamok Ebon") ;
    set("long", wrap("Adamok is a short, stocky bladeling with a "+
    "reputation for being short-tempered and very skilled with "+
    "her twin blades."));
	set ("id", ({ "adamok", "ebon", "bladeling" }) ) ;
    set_size(4) ;
	set_name ("adamok") ;
	set ("race", "bladeling");
	set ("gender", "female") ;
	enable_commands() ;
    set_living_name("adamok") ;
	set ("stat/constitution", 16);
	set ("stat/strength", 16);
	set ("stat/charisma",8);
	set ("stat/intelligence", 15);
	set ("stat/dexterity", 13);
	set ("stat/wisdom", 14);
	set("CLASS", "warrior");
	set ("damage", ({ 1,4 }) ) ;
	set ("weapon_name", "fists") ;
	set_skill("Short Blades", 3, "Strength") ;
	set_skill("Ambidexterity", 1, "Strength") ;
	set_skill("Two Weapon Style", 2, "Strength") ;
	set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
    wear(OBJ(freeactionring), "ring") ;
	set_level(11);
    arm(OBJ(greendagger), "dagger") ;
    arm(OBJ(greendagger), "dagger") ;
}

/* EOF */