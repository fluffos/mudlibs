
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
#include "../sigil.h"
inherit MONSTER ;


void create () {


	::create() ;
	seteuid(getuid()) ;
	set ("short", "Milori") ;
	set ("long", "The translator of sigil.\n") ;
	set ("id", ({ "milori", "lillend"}) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 200) ;
        set ("mass", 300) ;
        set ("bulk", 250) ;
	set_name ("milori") ;
	set ("race", "lillend");
		set ("gender", "female") ;
	enable_commands() ;
   	set_living_name("milori") ;
	set ("stat/constitution", 16);
	set ("stat/strength", 18);
	set ("stat/charisma", 16);
	set ("stat/intelligence", 16);
	set ("stat/dexterity", 12);
	set ("stat/wisdom", 10);
	set ("armor_class", 3);
	set ("base_ac", 3);
	set_level(9);
	set("level", 9);
	set("natt", 1);
	set ("thac0", 13);
	set("resist_type",([ "necromancy":0, "fire":50, "poison":0]));
	set("weap_resist", 1);
	set("magic_resist", 25);
	set ("damage", ({ 3, 13 }) ) ;
	set ("weapon_name", "tail") ;
	set ("CLASS", "rogue");
	set_skill("Short Blades", 2, "Strength") ;
	set_verbs( ({ "poke at", "stab at", "pierce at" }) ) ;

   	   	}
