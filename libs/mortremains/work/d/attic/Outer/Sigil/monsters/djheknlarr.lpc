
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
#include "../sigil.h"
inherit MONSTER ;


void create () {


	::create() ;
	seteuid(getuid()) ;
	set ("short", "Djheknlarr") ;
	set ("long", "It is told she sells maps of the mazes..., for a price.\n") ;
	set ("id", ({ "djheknlarr", "githyanki"}) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 200) ;
        set ("mass", 300) ;
        set ("bulk", 250) ;
	set_name ("djeheknlarr") ;
	set ("race", "githyanki");
		set ("gender", "female") ;
	enable_commands() ;
   	set_living_name("djheknlarr") ;
	set ("stat/constitution", 10);
	set ("stat/strength", 13);
	set ("stat/charisma", 7);
	set ("stat/intelligence", 13);
	set ("stat/dexterity", 15);
	set ("stat/wisdom", 11);
	set_level(11);
	set("level", 11);
	set("natt", 1);
	set ("thac0", 12);
	set ("damage", ({ 1,4 }) ) ;
	set ("weapon_name", "fists") ;
	set ("CLASS", "warrior");
	set_skill("Long Blades", 3, "Strength") ;
	set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
   arm(SIGIL+"items/sword2", "sword") ;
  wear(SIGIL+"items/braces6", "bracers") ;
}
