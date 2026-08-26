
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
inherit MONSTER ;


void create () {

	object ob1, ob2, ob3, ob4 ;

	::create() ;
	seteuid(getuid()) ;
	set ("short", "Iron Golem") ;
	set ("long", "A Magical Construct of Iron.\n") ;
	set ("id", ({ "iron", "golem", "iron golem"}) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("mass", 300) ;
    set_name ("iron golem") ;
	set ("gender", "male") ;
	set ("race", "golem");
	enable_commands() ;
   	set_living_name("iron golem") ;
	set ("stat/constitution", 20);
	set ("stat/strength", 24);
	set ("base_ac", 3);
	set ("armor_class", 3);
	set ("damage", ({ 4,40 }) ) ;
	set ("weapon_name", "iron fists") ;
	set ("CLASS", "warrior");
	set_verbs( ({ "smashes at", "swing at", "swipe at" }) ) ;
	set ("weap_resist", 3);
	set("resist_type", ([ "fire":-100 ]));
	set("magic_resist", 500);
	set_level(18);
	set("max_hp", 480);
	set("hit_points", 480);
}
