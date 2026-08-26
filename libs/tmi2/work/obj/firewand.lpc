// wand.of.fire.c
// A magic wand which casts the missile spell. It uses charges which can be
// used up. It uses the Magic item use skill.
// Written by Mobydick@TMI-2, 10-20-92

#include <mudlib.h>

inherit OBJECT ;

void create () {
	set ("short", "a wand of fire") ;
	set ("long", "This magic wand will cast the missile spell. If you \"use\" it on your\n victim, it will attack them with a magic missile.\n") ;
	set ("id", ({ "wand", "fire wand", "wand of fire" }) ) ;
	set("charges", 6+random(7)) ;
	set ("mass", 30) ;
	set ("bulk", 5) ;
// This is a totally unnecessary hack until Buddha fixes some damn thing.
	set ("value", ({ 30, "gold" }) ) ;
	seteuid(getuid()) ;
}

void init() {
	add_action("cast_missile", "use") ;
}

int cast_missile (string str) {

	string targname ;
	int damage, hp, charges, skill ;
	object target ;

	if (this_player()->query("stop_attack")>0) {
		write ("You are too busy to do that right now.\n") ;
		return 1 ;
	}
	if (!str) {
		notify_fail("Use the wand on whom?\n") ;
		return 0 ;
	}
	if (sscanf(str,"wand on %s",targname) != 1) {
		notify_fail ("What do you want to use the wand on?\n") ;
		return 0 ;
	}
	target = find_living(targname) ;
	if (!target) {
		notify_fail ("I don't see that here.\n") ;
		return 0 ;
	}
	if (target==this_player()) {
		notify_fail ("I don't think you want to do that.\n") ;
		return 0 ;
	}
	if (environment(target) != environment(this_player())) {
		notify_fail ("That is not here to be pointed at.\n") ;
		return 0 ;
	}
	this_player()->block_attack(2) ;
	target->kill_ob(this_player()) ;
	this_player()->set_target(target) ;
	this_player()->missile_effect() ;
	charges = query("charges") ;
	if (charges==1) {
		write ("The wand vanishes in a puff of smoke!\n") ;
		remove() ;
	}
	set ("charges", charges-1) ;
	return 1 ;
}
