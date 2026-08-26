
// A generic monster.

#include <mudlib.h>
#include "plane.h"
 
inherit MONSTER ;

void create () {
	::create() ;
	seteuid(getuid()) ;
        set ("short", "The captain");
        set ("long", "The captain of the ship. Be careful!\n");
        set ("id", ({ "captain", "the captain"}) );
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 200) ;
        set ("mass", 300) ;
        set ("bulk", 250) ;
        set_name ("captain");
	set ("gender", "male") ;
	enable_commands() ;
        set_living_name("captain");
        set ("stat/constitution", 20);
        set ("stat/strength", 20);
        set ("stat/charisma", 4);
        set ("stat/intelligence", 16);
        set ("stat/dexterity", 16);
	set ("stat/wisdom", 14);
	set("natt", 1);
	set ("thac0", 13);
	set ("damage", ({ 1,4 }) ) ;
	set ("weapon_name", "fists") ;
	set ("CLASS", "warrior");
	set_skill("Long Blades", 4, "Strength") ;
        set_level(22);
	set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
        wear(EQUIP(pirring), "ring");
        arm(WEAP(pirsword), "blade");
        wear(EQUIP(necklace), "necklace");
  }
