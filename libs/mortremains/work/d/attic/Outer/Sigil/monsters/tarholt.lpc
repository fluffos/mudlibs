
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
#include "../sigil.h"
inherit MONSTER ;


void create () {


	::create() ;
	seteuid(getuid()) ;
	set ("short", "Tarholt") ;
	set ("long", "A Dwarven Smith.\n") ;
	set ("id", ({ "tarholt", "smith"}) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 200) ;
        set ("mass", 300) ;
        set ("bulk", 250) ;
	set_name ("tarholt") ;
	set("race", "dwarf");
	set ("gender", "male") ;
	enable_commands() ;
   	set_living_name("tarholt") ;
	set ("stat/constitution", 19);
	set ("stat/strength", 14);
	set ("stat/charisma", 9);
	set ("stat/intelligence", 15);
	set ("stat/dexterity", 12);
	set ("stat/wisdom", 10);
	set_level(9);
	set("level", 9);
	set ("thac0", 12);
	set ("damage", ({ 1,4 }) ) ;
	set ("weapon_name", "fists") ;
	set ("CLASS", "warrior");
	set_skill("Axes", 3, "Strength") ;
	set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
   arm(OBJ(greenaxe), "axe") ; wear(OBJ(plate), "plate") ;
   	}
