
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
#include "../sigil.h"
inherit MONSTER ;


void create () {


	::create() ;
	seteuid(getuid()) ;
	set ("short", "Rule-Of-Three") ;
	set ("long", "The riddle master and information broker.\n") ;
	set ("id", ({ "rule", "ruleofthree", "rule of three"}) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 200) ;
        set ("mass", 100) ;
      	set_name ("ruleofthree") ;
	set ("gender", "male") ;
	enable_commands() ;
	set("race", "tanar'ri");
   	set_living_name("ruleofthree") ;
	set_level(6);
	set("level", 6);
	set("natt", 1);
	set ("thac0", 9);
	set ("stat/constitution", 19);
	set ("stat/strength", 19);
	set ("stat/charisma", 20);
	set ("stat/intelligence", 15);
	set ("stat/dexterity", 17);
	set ("stat/wisdom", 13);
	set ("damage", ({ 1,6 }) ) ;
	set ("weapon_name", "claws") ;
	set ("damage_type", "slashing");
	set ("armor_class", 1);
	set ("base_ac", 1);
	set ("CLASS", "warrior");
	set ("magic_resist", 30);
	set ("resist_type", ([ "cold" : 50, "fire" : 50, "electricity" : 0, "poison" : 0 ]) );
	set_skill("Short Blades", 3, "Strength") ;
	set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
   arm(OBJ(dagger3), "dagger") ;
  wear(OBJ(ring4), "ring") ;
   	}
