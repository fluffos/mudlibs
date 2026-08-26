
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
inherit MONSTER ;


void create () {

	object ob1, ob2, ob3, ob4 ;

	::create() ;
	seteuid(getuid()) ;
	set ("short", "Giant Ant") ;
	set ("long", "A huge carnivorous insect.\n") ;
	set ("id", ({ "gaint", "ant", "giant ant"}) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 200) ;
        set ("mass", 300) ;
        set ("bulk", 250) ;
     set_size(12);
	set_name ("gaint ant") ;
	set ("gender", "neuter") ;
        set ("race", "giant");
	enable_commands() ;
   	set_living_name("giant ant") ;
	set ("base_ac", 3);
	set ("armor_class", 3);
	set ("damage", ({ 2,8 }) ) ;
	set ("weapon_name", "pincers") ;
	set ("CLASS", "warrior");
	set_verbs( ({ "poke at", "nip at", "swipe at" }) ) ;
set_level(50);
}
