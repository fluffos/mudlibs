// Fireball spell. Mobydick, 11-1-92. May be changed in the future.

#include <mudlib.h>

inherit DAEMON ;

varargs int cast (string str, int obj) {

	object target ;
	int sp, cost, skill ;

	if (str!="NONE") {
		target = present(str,environment(this_player())) ;
		if (!target) {
			write ("You are not in combat with anyone.\n") ;
			return 1 ;
		}
		if (target==this_player()) {
			write ("That seems like a pretty bad idea.\n") ;
			return 1 ;
		}
		if (!living(target)) {
			write("Please don't damage the furniture.\n") ;
			return 1 ;
		}
		if ((int)target->query("no_attack")==1) {
			write ("You cannot attack that.\n") ;
			return 1 ;
		}
	}
// If obj==1, it means the call came from an object, not the cast command,
// and we don't want to charge spell point cost.
	if (obj!=1) {
		sp = this_player()->query("spell_points") ;
		skill = this_player()->query_skill("Combat spells") ;
        	cost = 300/(skill+10) ;
        	if (sp<cost) {
                	write ("You haven't got enough spell points to cast it.\n") ;
                	return 1 ;
		}
        	this_player()->set ("spell_points", sp-cost) ;
	}
	if (str!="NONE") {
		write ("You attack "+str+"!\n") ;
		this_player()->kill_ob(target) ;
	}
	this_player()->fireball_cast(target) ;
	this_player()->improve_skill("Combat spells", 10) ;
	return 1 ;
}
