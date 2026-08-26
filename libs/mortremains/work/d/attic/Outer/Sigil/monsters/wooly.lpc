
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
#include "../sigil.h"
inherit MONSTER ;


void create () {


	::create() ;
	seteuid(getuid()) ;
	set ("short", "Wooly Cupgrass") ;
	set ("long", "A sensate alchemist bent upon trying out everything.\n") ;
	set ("id", ({ "wooly", "cupgrass"}) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 200) ;
        set ("mass", 300) ;
        set ("bulk", 250) ;
	set_name ("wooly") ;
	set ("race", "bariaur");
		set ("gender", "male") ;
	enable_commands() ;
   	set_living_name("wooly") ;
	set ("stat/constitution", 11);
	set ("stat/strength", 10);
	set ("stat/charisma", 16);
	set ("stat/intelligence", 16);
	set ("stat/dexterity", 12);
	set ("stat/wisdom", 14);
	set_level(7);
	set("level", 7);
	set("natt", 1);
	set ("thac0", 11);
	set ("damage", ({ 1,4 }) ) ;
	set ("weapon_name", "fists") ;
	set ("CLASS", "warrior");
	set_skill("Short Blades", 2, "Strength") ;
	set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
  arm(OBJ(dagger2), "dagger") ;
   
   	   	}
