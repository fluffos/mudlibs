// A test monster. It heals itself all the time. It's not dangerous but it
// can be kinda hard to kill.
// Mobydick, 10-7-92.

#include <mudlib.h>
#include <money.h>

inherit MONSTER ;

void create () {

	object money ;

	::create();
	seteuid(getuid()) ;
	set ("short", "a hypochondriac orc") ;
	set("long", "This orc thinks it always needs to be healed.\n") ;
	set ("id", ({ "orc", "hypochondriac" }) ) ;
	set ("mass", 3000) ;
	set ("bulk", 250) ;
	set ("capacity", 10000) ;
	set ("volume", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set_name("orc") ;
	enable_commands() ;
	set_living_name("orc") ;
	set ("gender", "male") ;
	set ("hit_points", 18) ;
	set ("armor_class", 0) ;
	set ("max_hp",18) ;
	set ("attack_strength", 5) ;
	set ("damage", ({ 2,7 }) ) ;
	set ("weapon_name", "fists") ;
	set ("stat/strength", 4) ;
	set ("stat/dexterity", 6) ;
	set_skill("attack", 3, "strength") ;
	set_skill("defense", 8, "dexterity") ;
	set_verbs( ({ "poke at", "hide behind", "pummel" }) ) ;
	spell_cast("heal",95) ;
	money = clone_object(COINS) ;
	money->set_type("gold") ;
	money->set_number(25) ;
	money->move(this_object()) ;
}
