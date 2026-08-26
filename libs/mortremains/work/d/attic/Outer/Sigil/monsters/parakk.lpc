
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
#include "../sigil.h"
inherit MONSTER ;


void create () {


	::create() ;
	seteuid(getuid()) ;
	set ("short", "Parakk") ;
	set ("long", "A spindly ratcatcher.\n") ;
	set ("id", ({ "parakk", "ratcatcher"}) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 200) ;
        set ("mass", 300) ;
        set ("bulk", 250) ;
	set_name ("parakk") ;
	set ("gender", "male");
	set ("race", "githzerai");
	enable_commands() ;
   	set_living_name("parakk") ;
	set ("stat/constitution", 12);
	set ("stat/strength", 11);
	set ("stat/charisma", 9);
	set ("stat/intelligence", 17);
	set ("stat/dexterity", 14);
	set ("stat/wisdom", 13);
set_level(5);
	set("level", 2);
	set("natt", 1);
	set ("damage", ({ 1,4 }) ) ;
	set ("weapon_name", "fists") ;
	set ("CLASS", "warrior");
	set_skill("Short Blades", 1, "Strength") ;
	set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
   arm(OBJ(greendagger), "dagger") ;
   wear(OBJ(cloak1), "cloak") ;
   	}
