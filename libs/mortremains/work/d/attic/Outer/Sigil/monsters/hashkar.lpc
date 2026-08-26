
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
inherit MONSTER ;


void create () {


	::create() ;
	seteuid(getuid()) ;
	set ("short", "Factol Hashkar") ;
	set ("long", "The Factol of the Fraternity of Order.\n") ;
	set ("id", ({ "factol", "hashkar", "dwarf"}) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 200) ;
        set ("mass", 300) ;
        set ("bulk", 250) ;
	set_name ("hashkar") ;
	set ("gender", "male") ;
	enable_commands() ;
   	set_living_name("hashkar") ;
	set ("stat/constitution", 18);
	set ("stat/strength", 9);
	set ("stat/charisma", 8);
	set ("stat/intelligence", 24);
	set ("stat/dexterity", 10);
	set ("stat/wisdom", 22);
	set_level(1);
	set("level", 1);
	set("natt", 1);
	set ("thac0", 20);
	set ("damage", ({ 1,3 }) ) ;
	set ("weapon_name", "fists") ;
	set ("CLASS", "none");
	set_skill("Short Blades", 3, "Strength") ;
		set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
    
   		}

