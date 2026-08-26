
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
inherit MONSTER ;


void create () {

	object ob1, ob2, ob3, ob4 ;

	::create() ;
	seteuid(getuid()) ;
        set ("short", "Master Water Elemental") ;
        set ("long", "A being made of pure water.\n"+
        "You can tell that he is unusually powerful.") ;
        set ("id", ({ "elemental", "water elemental", "master", "master water elemental" }) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 200) ;
        set ("mass", 300) ;
        set ("bulk", 250) ;
        set_name ("master water elemental") ;
	set ("gender", "male") ;
	set ("race", "elemental");
	enable_commands() ;
        set_living_name ("master water elemental") ;
	set ("stat/constitution", 20);
	set ("stat/strength", 18);
        set ("stat/dexterity", 16);
        set ("stat/intelligence", 10);
        set ("stat/wisdom", 8);
        set ("stat/charisma", 12);
	set ("base_ac", 2);
	set ("armor_class", 2);
        set ("damage", ({ 7,50 }) ) ;
	set ("weapon_name", "watery fists") ;
	set ("CLASS", "warrior");
	set_verbs( ({ "pummel on", "swing at", "swipe at" }) ) ;
	set ("weap_resist", 2);
        TO -> resistance("fire", 200);
        TO -> resistance("water", 50);
        set("no_attack", 1);
        set("wealth", random(100000) + 50000);
        set_level(30);
}
