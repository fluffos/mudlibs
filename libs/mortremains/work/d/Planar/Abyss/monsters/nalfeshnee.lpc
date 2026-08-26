
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
inherit MONSTER ;


void create () {

	object ob1, ob2 ;

	::create() ;
seteuid(getuid()) ;
	set ("short", "Nalfeshnee") ;
	set ("long", "A Fat, Bloated Demon of the abyss.\n") ;
	set ("id", ({ "nalfeshnee",  "tanar'ri" }) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 10000) ;
        set ("mass", 3000) ;
        set ("bulk", 250) ;
	set_name ("gabberslug") ;
	set ("race", "tanar'ri");
	set ("gender", "male") ;
	enable_commands() ;
   	   	set_living_name("nalfeshnee") ;
	set("resist_type",([ "cold":50, "fire":50, "poison":0, "electrical":0]));
	set("weap_resist", 2);
	set ("stat/constitution", 20);
	set ("stat/strength", 20);
	set ("stat/charisma",8);
	set ("stat/intelligence", 15);
	set ("stat/dexterity", 13);
	set ("stat/wisdom", 14);
	set_level(11);
		set ("base_ac", -8);
	set ("armor_class", -8);
		set("natt", 3);
	set("CLASS", "warrior");
	set ("damage", ({ 1,4 }) ) ;
	set ("weapon_name", "claws") ;
	set_verbs( ({ "rip", "slash at", "swipe at" }) ) ;
	}
