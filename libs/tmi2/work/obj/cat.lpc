// cat.c
// A generic moving monster. Wanders around on its own power.
// Comments on monster properties are found in /obj/foobird.c
// Mobydick, 3-29-93.

#include <mudlib.h>

inherit MONSTER ;

void create () {

	object ob1, ob2, ob3 ;

	::create() ;
	seteuid(getuid()) ;
	set ("short", "a black cat") ; 
	set ("long",
"The cat is large and is jet black all over. It smirks back at you in the\n"+
"way that cats everywhere do.\n") ;
	set ("id", ({ "cat", "black cat" }) ) ;
	set ("capacity", 500) ;
	set ("max_cap", 500) ;
	set ("max_vol", 100) ;
	set ("volume", 100) ;
        set ("mass", 1500) ;
        set ("bulk", 120) ;
	set_name ("cat") ;
	set ("gender", "male") ;
	enable_commands() ;
	set_living_name("cat") ;
	set ("hit_points", 10) ;
	set ("max_hp",10) ;
	set ("attack_strength", 12) ;
	set ("damage", ({ 2,4 }) ) ;
	set ("weapon_name", "claws") ;
	set ("stat/strength", 6) ;
	set ("stat/dexterity", 22) ;
	set_skill("attack", 12, "strength") ;
	set_skill("defense", 14, "dexterity") ;
	set_verbs( ({ "slash at", "lunge at", "swipe at" }) ) ;
// This monster moves around by itself.
	set ("moving", 1) ;
	set ("speed", 8) ;
}
