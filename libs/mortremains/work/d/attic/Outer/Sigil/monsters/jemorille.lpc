
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
#include "../sigil.h"
inherit MONSTER ;


void create () {


	::create() ;
	seteuid(getuid()) ;
	set ("short", "Colcook") ;
	set ("long", "Shemeshka's manservant.\n") ;
	set ("id", ({ "jemorille", "colcook", "exile" }) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 200) ;
        set ("mass", 300) ;
        set ("bulk", 250) ;
	set_name ("colcook") ;
	set ("gender", "male") ;
	enable_commands() ;
	set ("race", "rilmani");
   	set_living_name("colcook") ;
	set ("stat/constitution", 16);
	set ("stat/strength", 19);
	set ("stat/charisma", 18);
	set ("stat/intelligence", 19);
	set ("stat/dexterity", 11);
	set ("stat/wisdom", 20);
		set("natt", 2);
	set ("thac0", 11);
	set ("armor_class", -1);
	set ("base_ac", -1);
	set ("damage", ({ 1,6 }) ) ;
	set ("weapon_name", "claws") ;
	set ("CLASS", "wizard");
	set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
	set ("resist_type", ([ "poison" : 50, "electricity" : 0, "acid" : 50 ]) );
	set ("weap_resist", 3);
	set("magic_resist", 55);
	set_level(9);
	set("level", 9);
	set_skill("Short Blades", 2, "Strength") ;
  arm(OBJ(dagger3), "dagger") ;
}
