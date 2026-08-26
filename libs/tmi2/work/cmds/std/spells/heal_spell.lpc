// Healing spell.
// Mobydick, 11-3-92. If you didn't vote, you get what you deserve...

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
		write ("That person is not here to be healed.\n") ;
		return 1 ;
	}
	if (!living(target)) {
		write ("It will have no effect on that.\n") ;
		return 1 ;
	}
// If obj==1, then the call came from an object and we do not want to
// assess the spell point cost.
	if (obj!=1) {
		sp = this_player()->query("spell_points") ;
		skill = this_player()->query_skill("Healing spells") ;
        	cost = 100/(skill+10) ;
        	if (sp<cost) {
                	write ("You haven't got enough spell points to cast it.\n") ;
                	return 1 ;
		}
        	this_player()->set ("spell_points", sp-cost) ;
	}
	this_player()->heal_cast(target) ;
	this_player()->improve_skill("Healing spells", 5) ;
	return 1 ;
}
