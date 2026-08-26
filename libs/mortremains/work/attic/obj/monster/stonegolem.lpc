
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
inherit MONSTER ;


void create () {

	object ob1, ob2, ob3, ob4 ;

	::create() ;
	seteuid(getuid()) ;
	set ("short", "Stone Golem") ;
	set ("long", "A Magical Construct of Stone.\n") ;
	set ("id", ({ "stone", "golem", "stone golem"}) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("mass", 500) ;
    set_name ("stone golem") ;
	set ("gender", "male") ;
	set ("race", "golem");
	enable_commands() ;
   	set_living_name("stone golem") ;
	set ("stat/constitution", 20);
	set ("stat/strength", 22);
	set ("base_ac", 5);
	set ("armor_class", 5);
	set ("damage", ({ 4,40 }) ) ;
	set ("weapon_name", "stone fists") ;
	set ("CLASS", "warrior");
	set_verbs( ({ "smashes at", "swing at", "swipe at" }) ) ;
	set ("weap_resist", 2);
	set("magic_resist", 500);
	set_level(14);
	set("max_hp", 360);
	set("hit_points", 360);
}
