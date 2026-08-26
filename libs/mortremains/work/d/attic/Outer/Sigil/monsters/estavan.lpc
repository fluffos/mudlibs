
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
#include "../sigil.h"
inherit MONSTER ;


void create () {


	::create() ;
	seteuid(getuid()) ;
	set ("short", "Estavan") ;
	set ("long", "A bookeeper for factol Darkwood.\n") ;
	set ("id", ({ "estavan", "ogre"}) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 200) ;
        set ("mass", 300) ;
        set ("bulk", 250) ;
	set_name ("estavan") ;
	set ("race", "ogre");
		set ("gender", "male") ;
	enable_commands() ;
   	set_living_name("estavan") ;
	set ("stat/constitution", 18);
	set ("stat/strength", 19);
	set ("stat/charisma", 7);
	set ("stat/intelligence", 13);
	set ("stat/dexterity", 15);
	set ("stat/wisdom", 11);
	set_level(6);
	set("level", 6);
	set("natt", 1);
	set ("thac0", 15);
	set ("damage", ({ 1,4 }) ) ;
	set ("weapon_name", "fists") ;
	set ("CLASS", "wizard");
	set_skill("Clubbing Weapons", 2, "Strength") ;
	set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
  arm(SIGIL+"items/greenmace", "mace") ;
   	   	}
