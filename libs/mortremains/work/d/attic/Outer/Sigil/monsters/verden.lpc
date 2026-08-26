
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
#include "../sigil.h"
inherit MONSTER ;


void create () {


	::create() ;
	seteuid(getuid()) ;
	set ("short", "Verden") ;
	set ("long", "A sultry, inviting elf.\n") ;
	set ("id", ({ "verden", "slut"}) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 200) ;
        set ("mass", 300) ;
        set ("bulk", 250) ;
	set_name ("verden") ;
	set ("gender", "female") ;
	set ("race", "elf");
	enable_commands() ;
   	set_living_name("verden") ;
	set ("stat/constitution", 10);
	set ("stat/strength", 9);
	set ("stat/charisma", 16);
	set ("stat/intelligence", 14);
	set ("stat/dexterity", 17);
	set ("stat/wisdom", 13);
	set_level(11);
	set("level", 11);
	set("natt", 1);
	set ("thac0", 15);
	set ("damage", ({ 1,4 }) ) ;
	set ("weapon_name", "fists") ;
	set ("CLASS", "thief");
	set_skill("Short Blades", 2, "Strength") ;
	set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
  arm(OBJ(dagger4), "dagger") ;
  wear(OBJ(leather3), "leather") ;
  wear(OBJ(ring3), "ring") ;
  wear(OBJ(regenring), "ring") ;
   	}
