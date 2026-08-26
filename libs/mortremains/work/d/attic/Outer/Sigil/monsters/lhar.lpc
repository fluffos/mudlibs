
// A generic monster.

#include <mudlib.h>
#include "../sigil.h"
inherit MONSTER ;


void create () {


	::create() ;
	seteuid(getuid()) ;
	set ("short", "Factol Lhar") ;
	set ("long", "The Factol of the Bleak Cabal.\n") ;
	set ("id", ({ "factol", "lhar"}) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 200) ;
        set ("mass", 300) ;
        set ("bulk", 250) ;
	set_name ("lhar") ;
	set ("gender", "male") ;
	enable_commands() ;
   	set_living_name("lhar") ;
	set ("stat/constitution", 14);
	set ("stat/strength", 16);
	set ("stat/charisma", 8);
	set ("stat/intelligence", 10);
	set ("stat/dexterity", 9);
	set ("stat/wisdom", 14);
	set_level(8);
	set("level", 8);
	set("natt", 1);
	set ("thac0", 13);
	set ("damage", ({ 1,4 }) ) ;
	set ("weapon_name", "fists") ;
	set ("CLASS", "warrior");
	set_skill("Long Blades", 4, "Strength") ;
	set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
  arm(OBJ(greensword), "sword" ) ;
  }
