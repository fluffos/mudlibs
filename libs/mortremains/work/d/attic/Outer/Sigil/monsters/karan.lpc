
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
#include "../sigil.h"
inherit MONSTER ;

void create () {


	::create() ;
	seteuid(getuid()) ;
	set ("short", "Factol Karan") ;
	set ("long", "The Factol of the Xaositects.\n") ;
	set ("id", ({ "factol", "karan"}) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 200) ;
        set ("mass", 300) ;
        set ("bulk", 250) ;
	set_name ("karan") ;
	set ("gender", "male") ;
	enable_commands() ;
   	set_living_name("karan") ;
	set ("stat/constitution", 18);
	set ("stat/strength", 17);
	set ("stat/charisma", 17);
	set ("stat/intelligence", 16);
	set ("stat/dexterity", 17);
	set ("stat/wisdom", 15);
	set_level(9);
	set("level", 9);
	set("natt", 1);
	set ("thac0", 12);
	set ("damage", ({ 1,4 }) ) ;
	set ("weapon_name", "fists") ;
	set ("CLASS", "warrior");
	set_skill("Long Blades", 4, "Strength") ;
	set_skill("Ambidexterity", 1, "Strength");
	set_skill("Two Weapon Style", 2, "Strength");
	set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
  arm(OBJ(greensword), "sword") ;
  arm(OBJ(greensword), "sword") ;
  wear(OBJ(greenchain), "chain") ;
       		}

