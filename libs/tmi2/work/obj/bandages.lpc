// bandage.c
// This is a bandage which you can use on a player to heal up some hit points.
// Mobydick@TMI-2, 10-27-92

#include <mudlib.h>

inherit OBJECT ;

void create() {
	set ("short", "a bandage") ;
	set ("long", "If you \"bandage\" a player, that player will get some hit points back.\n") ;
	set ("id", ({ "bandage", "bandages" }) ) ;
	set ("value", ({ 5, "silver" }) ) ;
	set ("mass", 5) ;
	set ("bulk", 5) ;
}

void init() {
	add_action("bandage", "bandage") ;
}

int bandage (string name) {

	object target ;
	int hp, mhp, skill, i ;
	target = present(name,environment(this_player())) ;
	if (!target) {
		notify_fail ("I don't see that here.\n") ;
		return 0 ;
	}
	if (!living(target)) {
		notify_fail ("Bandages should be used on living objects.\n") ;
		return 0 ;
	}
	target = find_player(name) ;
	hp = target->query("hit_points") ;
	mhp = target->query("max_hp") ;
	if (mhp==hp) {
		notify_fail (capitalize(name)+" does not need healing.\n") ;
		return 0 ;
	}
	skill = this_player()->query_skill("First aid") ;
	this_player()->improve_skill("First aid", 5) ;
	i = random(7)+4+skill/10 ;
	hp = hp + i ;
	if (hp>mhp) hp=mhp ;
	this_player()->set("hit_points", hp) ;
	write (capitalize(name)+" has been healed.\n") ;
	tell_object (target, "You are healed by "+this_player()->query("cap_name")+".\n") ;
	say (this_player()->query("cap_name")+" heals "+capitalize(name)+".\n",target) ;
	remove() ;
	return 1 ;
}
