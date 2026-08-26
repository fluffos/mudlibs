// Invisibility spell. Mobydick, 11-4-92.

#include <mudlib.h>

inherit DAEMON ;

varargs int cast (string str, int obj) {

	object target ;
	int sp, cost, skill ;

	if (str=="NONE") {
		target = this_player() ;
	} else {
		target = present(str,environment(this_player())) ;
	}
	if (!target) {
		write ("Who would you like to turn invisible?\n") ;
		return 1 ;
	}
	if (!living(target)) {
		write("You do not have the ability to do that.\n") ;
		return 1 ;
	}
// If obj==1, then the call came from an object and we do not assess
// the spell point cost.
	if (obj!=1) {
		sp = this_player()->query("spell_points") ;
		skill = this_player()->query_skill("Divinations spells") ;
        	cost = 150/(skill+10) ;
        	if (sp<cost) {
                	write ("You haven't got enough spell points to cast it.\n") ;
                	return 1 ;
		}
        	this_player()->set ("spell_points", sp-cost) ;
	}
	target->invis_cast() ;
	if (str!="NONE") {
		write ("You cast invisibility on "+target->query("cap_name")+".\n") ;
		tell_object(target,this_player()->query("cap_name")+" casts invisibility on you.\n") ;
	}
	this_player()->improve_skill("Divinations spells", 5) ;
	return 1 ;
}
