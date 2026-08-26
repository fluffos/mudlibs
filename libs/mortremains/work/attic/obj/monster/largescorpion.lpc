
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
inherit MONSTER ;


void create () {

	object ob1, ob2, ob3, ob4 ;

	::create() ;
	seteuid(getuid()) ;
	set ("short", "Large Scorpion") ;
	set ("long", "A large poisionous insect.\n") ;
	set ("id", ({ "large", "scorpion", "large scorpion"}) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 200) ;
        set ("mass", 300) ;
        set ("bulk", 250) ;
        set_size(5);
	set_name ("large scorpion") ;
	set ("gender", "neuter") ;
	set ("race", "insect");
	enable_commands() ;
   	set_living_name("large scorpion") ;
	set ("base_ac", 5);
	set ("armor_class", 5);
	set ("damage", ({ 1,4 }) ) ;
	set ("weapon_name", "pincers") ;
	set ("CLASS", "warrior");
	set_verbs( ({ "slash at", "swing at", "slice at" }) ) ;
	set_level(3);
}
