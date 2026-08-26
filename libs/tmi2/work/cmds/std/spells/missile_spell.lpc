// Missile spell. Mobydick, 10-31-92. In a state of flux.

#include <mudlib.h>

inherit DAEMON ;

varargs int cast (string str, int obj) {

	object target ;
	int sp, cost, skill ;

	if (str=="NONE") {
		target = this_player()->query_current_attacker() ;
	} else {
		target = present(str,environment(this_player())) ;
	}
	if (!target) {
		write ("Cast a magic missile at whom?\n") ;
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
		write ("You are not permitted to attack that.\n") ;
		return 1 ;
	}
// if obj==1, then the call came from an object and we don't want to
// assess the spell point cost.
	if (obj!=1) {
		sp = this_player()->query("spell_points") ;
		skill = this_player()->query_skill("Combat spells") ;
        	cost = 100/(skill+10) ;
        	if (sp<cost) {
                	write ("You haven't got enough spell points to cast it.\n") ;
                	return 1 ;
		}
        	this_player()->set ("spell_points", sp-cost) ;
	}
	if (str!="NONE") {
		write ("You attack "+str+"!\n") ;
	}
	this_player()->kill_ob(target) ;
	this_player()->missile_cast(target) ;
	this_player()->improve_skill("Combat spells", 5) ;
	return 1 ;
}
