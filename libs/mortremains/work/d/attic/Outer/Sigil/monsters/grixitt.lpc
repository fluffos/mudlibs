
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
#include "../sigil.h"
inherit MONSTER ;


void create () {


	::create() ;
	seteuid(getuid()) ;
	set ("short", "Grixitt") ;
	set ("long", "A reputed Portal-destroyer and thief of some note.\n") ;
	set ("id", ({ "grixitt", "bitch"}) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 200) ;
        set ("mass", 300) ;
        set ("bulk", 250) ;
	set_name ("grixitt") ;
	set ("race", "human");
		set ("gender", "female") ;
	enable_commands() ;
   	set_living_name("estavan") ;
	set ("stat/constitution", 15);
	set ("stat/strength", 16);
	set ("stat/charisma", 7);
	set ("stat/intelligence", 13);
	set ("stat/dexterity", 18);
	set ("stat/wisdom", 11);
	set_level(3);
	set("level", 3);
	set("natt", 1);
	set ("thac0", 18);
	set ("damage", ({ 1,4 }) ) ;
	set ("weapon_name", "fists") ;
	set ("CLASS", "rogue");
	set_skill("Short Blades", 2, "Strength") ;
	set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
  arm(OBJ(greendagger), "dagger") ;
   wear(OBJ(ring4), "ring") ;
   	   	}
