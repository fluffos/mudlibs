
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
inherit MONSTER ;


void create () {


	::create() ;
	seteuid(getuid()) ;
	set ("short", "a standard monster") ;
	set ("long", "It is a boring creature.\n") ;
	set ("id", ({ "monster", "it" }) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 10000) ;
        set ("mass", 3000) ;
        set ("bulk", 250) ;
	set_name ("it") ;
	set ("gender", "neuter") ;
	enable_commands() ;
   	set_living_name("it") ;
	set_level(1);
	set ("damage", ({ 1,4 }) ) ;
	set ("weapon_name", "claws") ;
	set_skill("Long Blades", 2, "Strength") ;
	set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
}
