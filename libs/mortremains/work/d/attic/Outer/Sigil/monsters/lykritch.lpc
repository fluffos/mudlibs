
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
#include "../sigil.h"
inherit MONSTER ;


void create () {


	::create() ;
	seteuid(getuid()) ;
	set ("short", "Ly'kritch") ;
	set ("long", "A Shadowy soul-devouring monster.\n") ;
	set ("id", ({ "lykritch", "fiend"}) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 200) ;
        set ("mass", 100) ;
      	set_name ("lykritch") ;
	set ("gender", "male") ;
	enable_commands() ;
	set("race", "shadow fiend");
   	set_living_name("lykritch") ;
	set_level(8);
	set("level", 8);
	set("natt", 4);
	set ("thac0", 14);
	set ("damage", ({ 1,7 }) ) ;
	set ("weapon_name", "claws") ;
	set ("damage_type", "slashing");
	set ("armor_class", 1);
	set ("base_ac", 1);
	set ("CLASS", "warrior");
	set ("resist_type", ([ "cold" : 0, "fire" : 0, "electricity" : 0, "necromancy" : 0, "slashing" : 50, "piercing" : 50, "bludgeoning" : 50 ]) );
	set_verbs( ({ "slash", "scratch", "poke" }) ) ;
	}
