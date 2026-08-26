
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
#include "../sigil.h"
inherit MONSTER ;


void create () {


	::create() ;
	seteuid(getuid()) ;
	set ("short", "Omott") ;
	set ("long", "An inquisitive would-be god.\n") ;
	set ("id", ({ "omott", "linqua"}) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 200) ;
        set ("mass", 300) ;
        set ("bulk", 250) ;
	set_name ("omott") ;
	set ("gender", "male") ;
	enable_commands() ;
	set("race", "linqua");
   	set_living_name("omott") ;
	set_level(3);
	set("level", 3);
	set("natt", 1);
	set ("thac0", 17);
	set ("damage", ({ 1,4 }) ) ;
	set ("weapon_name", "fists") ;
	set ("CLASS", "rogue");
	set_skill("Clubbing Weapons", 2, "Strength") ;
	set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
	set ("magic_resist", 5);
	set ("resist_type", ([ "cold" : 50, "acid" : 50, "fire" : 50 ]) );
  arm(OBJ(mace2), "mace") ;
   	}
