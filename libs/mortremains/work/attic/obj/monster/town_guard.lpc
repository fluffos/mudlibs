// town_guard.c
// A pursuing monster. That is, if you are in combat with him, and
// you leave, he'll go after you. You can lose him if you run fast
// enough but otherwise he's pretty lethal.
// Also, if A attacks B, then the guard will attack A.
// Comments on monster properties are found in /obj/foobird.c
// Written by Mobydick, 6-20-93.

#include <mudlib.h>

inherit MONSTER ;

void create () {

	object ob1, ob2, ob3 ;

	::create() ;
	seteuid(getuid()) ;
	set ("short", "a guard") ;
	set ("long", "He wears the livery of the Footown Police.\n") ;
	set ("id", ({ "guard", "town guard" }) ) ;
	set_name ("guard") ;
	set ("gender", "male") ;
	ob1 = clone_object ("/obj/sword") ;
	ob1 -> move (this_object()) ;
	wield_weapon(ob1) ;
	ob2 = clone_object("/obj/shield") ;
	ob2 -> move (this_object()) ;
	equip_armor (ob2) ;
	ob3 = clone_object("/obj/chainmail") ;
	ob3 -> move (this_object()) ;
	equip_armor(ob3) ;
	set_living_name("guard") ;
	set ("hit_points", 40) ;
	set ("max_hp",40) ;
	set ("attack_strength", 5) ;
	set ("damage", ({ 1,4 }) ) ;
	set ("weapon_name", "fists") ;
	set ("stat/strength", 13) ;
	set ("stat/dexterity", 11) ;
	set_skill("attack", 3, "strength") ;
	set_skill("defense", 8, "dexterity") ;
	set ("pursuing", 1) ;
	set ("inquiry", ([
"guarding" : "My job is to prevent people from attacking each other.",
"attacking" : "If you attack someone, I will attack you, and chase you.",
"footown" : "Footown is a very nice place, where people don't attack each other." ,
"livery" : "It's not very nice fabric but it's an attractive color."
	]) ) ;
	set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
}

void relay_message(string Class, string str) {

	string attacker, victim ;
	object fellow ;

	if (str && sscanf(str,"%s attacks %s",attacker,victim)) {
	     if (sizeof(attackers)==0) {
		fellow = find_living(lower_case(attacker)) ;
		if (fellow) {
			kill_ob(fellow) ;
			tell_object(fellow,"The guard attacks you!\n") ;
			say ("The guard attacks "+fellow->query("cap_name")+
					"!\n") ;
		}
	    }
	}
	::relay_message (Class, str) ;
}
