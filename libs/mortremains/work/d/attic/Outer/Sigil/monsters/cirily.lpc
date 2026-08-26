
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
inherit MONSTER ;


void create () {


	::create() ;
	seteuid(getuid()) ;
	set ("short", "Cirily") ;
	set ("long", "A planar supremecist.\n") ;
	set ("id", ({ "cirily", "eladrin"}) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 200) ;
        set ("mass", 300) ;
        set ("bulk", 250) ;
	set_name ("cirily") ;
	set ("gender", "female") ;
	set ("race", "eladrin");
	enable_commands() ;
	set ("stat/constitution", 16);
	set ("stat/strength", 16);
	set ("stat/charisma", 8);
	set ("stat/intelligence", 14);
	set ("stat/dexterity", 10);
	set ("stat/wisdom", 10);
	set("natt", 2);
	set ("thac0", 13);
	set ("base_ac", -3);
	set ("armor_class", -3);
	set ("damage", ({ 3,18 }) ) ;
	set ("weapon_name", "flaming fists") ;
	set ("CLASS", "warrior");
	set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
	set ("resist_type", ([ "cold" : 0, "poison" : 50, "fire" : 50, "electricity" : 0, "force" : 0 ]) );
	set ("weap_resist", 2);
	set ("magic_resist", 40);
	set_level(8);
}
