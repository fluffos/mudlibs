
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
inherit MONSTER ;


void create () {

	object ob1, ob2, ob3, ob4 ;

	::create() ;
	seteuid(getuid()) ;
	set ("short", "Twelve headed Hydra") ;
	set ("long", "Hydrae are immense reptilian monsters with multiple heads. .\n") ;
	set ("id", ({ "hydra" }) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 200) ;
        set ("mass", 300) ;
        set ("bulk", 250) ;
        set_size(16);
	set_name ("hydra") ;
	set ("gender", "neuter") ;
	set ("race", "hydra");
	enable_commands() ;
   	set_living_name("hydra") ;
	set ("base_ac", 5);
	set ("armor_class", 5);
	set ("natt", 6);
	set ("damage", ({ 2,20 }) ) ;
	set ("weapon_name", "bite") ;
	set ("CLASS", "warrior");
	set_verbs( ({ "slash at", "chomp on", "slice at" }) ) ;
	set_level(12);
}
