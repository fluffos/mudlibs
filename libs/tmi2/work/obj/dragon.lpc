// dragon.c
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c
// Mobydick, 10-2-92.

#include <mudlib.h>
 
inherit MONSTER ;


void create () {

	object ob1, ob2, ob3 ;

	seteuid(getuid()) ;
	::create() ;
	init_commands() ;
	set ("short", "Curly the red dragon") ;
	set ("long", "The dragon has a large red body with powerful silver" +
	     " wings. It has\na faint aura of smoke about it. Use caution " +
	     "adventurer...\n");
	set ("id", ({ "dragon", "red dragon", "curly" }) ) ;
	set ("capacity", 10000) ;
	set ("volume", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
        set ("mass", 3000) ;
        set ("bulk", 250) ;
	set_name ("curly") ;
	set ("gender", "neuter") ;
	enable_commands() ;
	set_living_name("curly") ;
	set ("hit_points", 70) ;
	set ("max_hp",70) ;
	set ("attack_strength", 1) ;
	set ("damage", ({ 1,4 }) ) ;
	set ("weapon_name", "paws") ;
	set ("stat/strength", 4) ;
	set ("stat/dexterity", 6) ;
	set_skill("attack", 3, "strength") ;
	set_skill("defense", 8, "dexterity") ;
	set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
}

// This lets you give him a unique movement message.

string query_min() {
	return "Curly the dragon flies in and lands next to you with a sulfurous stench.\n" ;
}

string query_mout (string str) {
	return "Curly the dragon departs, leaving only the smell of kerosene in his wake.\n" ;
}
