// orc.c
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c
// Mobydick, 10-2-92.

#include <mudlib.h>
inherit MONSTER ;


void create () {

	object ob1, ob2 ;

	::create() ;
	seteuid(getuid()) ;
	set ("short", "an ugly orc") ;
	set ("long", "It is a small repugnant creature with a nasty glint in its eye.\n") ;
	set ("id", ({ "orc", "ugly orc" }) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 10000) ;
        set ("mass", 3000) ;
        set ("bulk", 250) ;
	set_name ("orc") ;
	set ("gender", "neuter") ;
	enable_commands() ;
	ob1 = clone_object ("/obj/sword") ;
	ob1 -> move (this_object()) ;
	wield_weapon(ob1) ;
	ob2 = clone_object("/obj/shield") ;
	ob2 -> move (this_object()) ;
	equip_armor (ob2) ;
	set_living_name("orc") ;
	set ("hit_points", 10) ;
	set ("max_hp",10) ;
	set ("attack_strength", 1) ;
	set ("damage", ({ 1,4 }) ) ;
	set ("weapon_name", "paws") ;
	set ("stat/strength", 4) ;
	set ("stat/dexterity", 6) ;
	set_skill("attack", 3, "strength") ;
	set_skill("defense", 8, "dexterity") ;
	set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
}
