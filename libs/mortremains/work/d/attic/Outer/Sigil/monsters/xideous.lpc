
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
#include "../sigil.h"
inherit MONSTER ;


void create () {


	::create() ;
	seteuid(getuid()) ;
	set ("short", "Xideous") ;
	set ("long", "A shator scholar of some renown.\n") ;
	set ("id", ({ "xideous", "gehreleth", "shator"}) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 200) ;
        set ("mass", 300) ;
        set ("bulk", 250) ;
	set_name ("xideous") ;
	set ("gender", "male") ;
	set ("race", "gehreleth");
	enable_commands() ;
   	set_living_name("xideous") ;
	set ("stat/constitution", 20);
	set ("stat/strength", 21);
	set ("stat/charisma", 8);
	set ("stat/intelligence", 20);
	set ("stat/dexterity", 10);
	set ("stat/wisdom", 10);
	set("natt", 3);
	set ("thac0", 5);
	set ("base_ac", -3);
	set ("armor_class", -3);
	set ("damage", ({ 9,18 }) ) ;
	set ("weapon_name", "claws") ;
	set ("CLASS", "warrior");
	set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
	set ("weap_resist", 3);
	set ("magic_resist", 50);
		set_level(15);
	set("level", 15);
}
