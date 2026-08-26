// This monster had 3 variables defined and did nothing with them.
// What a fucking waste of memory.  *applause for the lazy code* -Chronos

// Cyanide also cleaned and shit here.

#include <mudlib.h>
#include "defs.h"

inherit MONSTER ;

void create () {
	::create() ;
	seteuid(getuid()) ;
	set ("short", "A'Kin") ;
	set ("long", "The Friendly fiend himself.\n") ;
	set ("id", ({ "fiend", "akin", "a'kin"}) ) ;
	set_name ("akin") ;
	set_size(7);
	set ("stat/constitution", 16);
	set ("stat/strength", 17);
	set ("gender", "male") ;
	enable_commands() ;
   	set_living_name("akin") ;
	set("natt", 3);
	set ("armor_class", -8);
	set ("base_ac", -8);
	set ("thac0", 7);
	set ("damage", ({ 1,6 }) ) ;
	set ("weapon_name", "claws") ;
	set ("race", "yugoloth");
	set_verbs( ({ "slash at", "swing at", "swipe at" }) ) ;
	set("resist_type",([ "fire" : 0, "poison" : 0, "acid" : 0, 
	    "cold" : 200 ]) );
	set ("weap_resist", 3);	
    set_level(14);
}

/* EOF */