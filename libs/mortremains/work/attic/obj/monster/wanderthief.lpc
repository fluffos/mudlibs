// wanderthief.c
// A moving, object-stealing, high-wimpy monster.
// If it moves into your room, it will try to steal an object from you.
// Its wimpy is set to 100 so it will always run away if not at full
// strength.
// Comments on monster properties are found in /obj/foobird.c
// Written by Mobydick@TMI-2, 6-19-93

#include <mudlib.h>

inherit MONSTER ;

int in_theft ;
object victim, item ;

void create () {

	object ob1, ob2, ob3 ;

	::create() ;
	seteuid(getuid()) ;
	set ("short", "a small gnome") ;
	set ("long", "He has a rather shifty look about him which makes you feel uneasy.\n") ;
	set ("id", ({ "gnome", "thief" }) ) ;
	set ("capacity", 10000) ;
	set ("max_cap", 10000) ;
	set ("max_vol", 10000) ;
	set ("volume", 10000) ;
        set ("mass", 3000) ;
        set ("bulk", 250) ;
	set_name ("gnome") ;
	set ("gender", "neuter") ;
	ob1 = clone_object("obj/dagger") ;
	ob1->move(this_object()) ;
	wield_weapon(ob1) ;
	enable_commands() ;
	set_living_name("gnome") ;
	set ("hit_points", 25) ;
	set ("max_hp",25) ;
	set ("attack_strength", 1) ;
	set ("damage", ({ 1,4 }) ) ;
	set ("weapon_name", "paws") ;
	set ("stat/strength", 4) ;
	set ("stat/dexterity", 6) ;
	set_skill("attack", 3, "strength") ;
	set_skill("defense", 8, "dexterity") ;
	set_skill("Theft", 25, "dexterity") ;
	set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
	set ("wimpy", 99) ;
	set ("moving", 1) ;
	set ("speed", 16) ;
	set ("forgetful", 1) ;
	set ("chat_chance", 60) ;
	set ("chat_output", ({
		"The gnome bows and says, \"Top of the morning, sir!\"\n",
		"The gnome waves to you cheerfully.\n"
	}) ) ;
}

void init() {

	object *items, *people ;

	::init() ;
	if (in_theft) return 0 ;
	people = all_inventory(environment(this_object())) ;
	people = filter_array(people,"filter_people",this_object()) ;
	if (!people || sizeof(people)==0) return ;
	victim = people[random(sizeof(people))] ;
	items = all_inventory(victim) ;
	item = items[random(sizeof(items))] ;
	in_theft=1 ;
	call_out ("steal_item",2) ;
}

void steal_item() {

	string *itemnames ;
	string victimname ;

	in_theft=0 ;
	if (!present(victim,environment(this_object()))) return ;
	if (!present(item,victim)) return ;
	itemnames = (string *)item->query("id") ;
	victimname = victim->query("name") ;
	command("steal "+itemnames[0]+" from "+victimname) ;
}

int filter_people (object ob) {
	if (ob!=this_object() && living(ob) &&
		sizeof(all_inventory(ob))!=0) return 1 ;
	return 0 ;
}
