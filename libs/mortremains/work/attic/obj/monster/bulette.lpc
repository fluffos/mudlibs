
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
inherit MONSTER ;


void create () {

	object ob1, ob2, ob3, ob4 ;

	::create() ;
	seteuid(getuid()) ;
	set ("short", "Bulette") ;
	set ("long", "Aptly called a landshark, the bulette is a terrifying predator that lives only to eat.\n") ;
	set ("id", ({ "bulette" }) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 200) ;
        set ("mass", 300) ;
        set ("bulk", 250) ;
        set_size(10);
	set_name ("bulette") ;
	set ("gender", "neuter") ;
	set ("race", "bulette");
	enable_commands() ;
   	set_living_name("bulette") ;
	set ("base_ac", -2);
	set ("armor_class", -2);
	set ("natt", 2);
	set ("damage", ({ 3,18 }) ) ;
	set ("weapon_name", "claws") ;
	set ("CLASS", "warrior");
	set_verbs( ({ "slash at", "swing at", "slice at" }) ) ;
	set_level(9);
}
