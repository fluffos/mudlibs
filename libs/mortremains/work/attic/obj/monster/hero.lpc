// An example monster.
// This is a megadeath monster, great skills and stats, can wipe out
// most players without breaking a sweat.
// Comments on monster properties can be found in /obj/foobird.c
// Written by Mobydick, 11-6-92.

#include <mudlib.h>

inherit MONSTER ;

void create () {

	object ob1, ob2, ob3 ;

	::create() ;
	seteuid(getuid()) ;
	set ("short", "Bimbo, hero of the goblin wars") ;
	set ("long", "Bimbo is a skilled fighter. He has a steely glint in his eye.\n") ;
	set ("id", ({ "hero", "bimbo" }) ) ;
	set ("capacity", 5000) ;
	set ("volume", 500) ;
	set ("max_cap", 5000) ;
	set ("max_vol", 500) ;
        set ("mass", 3000) ;
        set ("bulk", 250) ;
	 set_name("bimbo") ;
	set ("gender", "male") ;
	set ("race", "human") ;
	enable_commands() ;
	ob1 = clone_object ("/obj/axe") ;
	ob1 -> move (this_object()) ;
	ob2 = clone_object ("/obj/shield") ;
	ob2 -> move (this_object()) ;
	ob3 = clone_object ("/obj/chainmail") ;
	ob3 -> move (this_object()) ;
	set_living_name("bimbo") ;
	enable_commands() ;
	set ("hit_points", 60) ;
	set ("armor_class", 0) ;
	set ("max_hp",60) ;
	set ("attack_strength", 0) ;
	set ("damage", ({ 1,4 }) ) ;
	set ("weapon_name", "fists") ;
	set ("stat/strength", 18) ;
	set ("stat/dexterity", 15) ;
	set_skill("attack", 38, "strength") ;
	set_skill("defense", 29, "dexterity") ;
	set_verbs( ({ "punch at", "swing at" }) ) ;
	set_verbs2( ({ "punches at", "swings at" }) ) ;
  	wield_weapon(ob1) ;
	equip_armor(ob2) ;
	equip_armor(ob3) ;
}
