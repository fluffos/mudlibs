
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
inherit MONSTER ;


void create () {

	object ob1, ob2, ob3, ob4 ;

	::create() ;
	seteuid(getuid()) ;
	set ("short", "Giant Frog") ;
	set ("long", "A huge carnivorous amphibian.\n") ;
	set ("id", ({ "giant", "frog", "giant frog"}) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 200) ;
        set ("mass", 300) ;
        set ("bulk", 250) ;
        set_size(10);
	set_name ("giant frog") ;
	set ("gender", "neuter") ;
	set ("race", "amphibian");
	enable_commands() ;
   	set_living_name("giant frog") ;
	set ("base_ac", 7);
	set ("armor_class", 7);
	set ("damage", ({ 2,8 }) ) ;
	set ("weapon_name", "mouth") ;
	set ("CLASS", "warrior");
	set_verbs( ({ "bite at", "nip at", "chomp on" }) ) ;
	set_level(3);
}
