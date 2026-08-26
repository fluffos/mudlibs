// hobgoblin.c
// A moving killer monster.
// A very nasty thing, since it will seek (move around) and
// destroy (attack any living object it finds. Will eat up much CPU
// if allowed to. This is here more for demonstration than because you
// would actually want to turn one loose. But, it does die quickly, so
// if you feel you need one of these, go ahead and clone it.
// Mobydick takes responsibility for turning it loose.
// Comments on monster properties are found in /obj/foobird.c
// Mobydick, 6-16-93.

#include <mudlib.h>
inherit MONSTER ;


void create () {

	object ob1, ob2, ob3 ;

	::create() ;
	seteuid(getuid()) ;
	set ("short", "a nasty hobgoblin") ;
	set ("long", "This dirty, smelly, and impolite monster seems to be rushing about in a\nmad, mad mood.\n") ;
	set ("id", ({ "goblin", "hobgoblin" }) ) ;
	set ("aggressive", 1) ;
	set ("moving", 1) ;
	set ("speed", 6) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 10000) ;
        set ("mass", 3000) ;
        set ("bulk", 250) ;
	set_name ("hobgoblin") ;
	set ("gender", "neuter") ;
	enable_commands() ;
	ob1 = clone_object ("/obj/sword") ;
	ob1 -> move (this_object()) ;
	wield_weapon(ob1) ;
	ob2 = clone_object("/obj/shield") ;
	ob2 -> move (this_object()) ;
	equip_armor (ob2) ;
	set_living_name("hobgoblin") ;
	set ("hit_points", 10) ;
	set ("max_hp",10) ;
	set ("attack_strength", 1) ;
	set ("damage", ({ 1,4 }) ) ;
	set ("weapon_name", "paws") ;
	set ("stat/strength", 16) ;
	set ("stat/dexterity", 12) ;
	set_skill("attack", 6, "strength") ;
	set_skill("defense", 10, "dexterity") ;
	set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
}
