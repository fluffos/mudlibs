
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
#include "../sigil.h"
inherit MONSTER ;


void create () {


	::create() ;
	seteuid(getuid()) ;
	set ("short", "Unity of Rings") ;
	set ("long", "An angel in a cell (hey even angels can go barmy!).\n") ;
	set ("id", ({ "unity", "unity of rings", "rings"}) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 200) ;
        set ("mass", 300) ;
        set ("bulk", 250) ;
	set_name ("unity") ;
	set ("gender", "male") ;
	set ("race", "aasimon");
	enable_commands() ;
   	set_living_name("unity") ;
	set ("stat/constitution", 17);
	set ("stat/strength", 17);
	set ("stat/charisma", 8);
	set ("stat/intelligence", 20);
	set ("stat/dexterity", 10);
	set ("stat/wisdom", 10);
	set("natt", 1);
	set ("thac0", 13);
	set ("base_ac", -1);
	set ("armor_class", -1);
	set ("damage", ({ 1,4 }) ) ;
	set ("weapon_name", "claws") ;
	set ("CLASS", "warrior");
	set ("weap_resist", 2);
	set ("magic_resist", 40);
	set ("resist_type", ([ "cold" : 0, "poison" : 0, "fire" : 50, "electricity" : 0, "force" : 0 ]) );
	set_skill("Long Blades", 2, "Strength") ;
	set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
		set_level(8);
	set("level", 8);
   
  arm(OBJ(flamesword1), "sword") ;
   	}
