
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
inherit MONSTER ;


void create () {

	object ob1, ob2, ob3, ob4 ;

	::create() ;
	seteuid(getuid()) ;
	set ("short", "Griffon") ;
	set ("long", "Half-lion, half-eagle, griffons are ferocious avian carnivores.\n") ;
	set ("id", ({ "griffon" }) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 200) ;
        set ("mass", 300) ;
        set ("bulk", 250) ;
        set_size(10);
	set_name ("griffon") ;
	set ("gender", "neuter") ;
	set ("race", "griffon");
	enable_commands() ;
   	set_living_name("griffon") ;
	set ("base_ac", 3);
	set ("armor_class", 3);
	set ("natt", 2);
	set ("damage", ({ 2,6 }) ) ;
	set ("weapon_name", "claws") ;
	set ("CLASS", "warrior");
	set_verbs( ({ "slash at", "swing at", "slice at" }) ) ;
	set_level(7);
}
