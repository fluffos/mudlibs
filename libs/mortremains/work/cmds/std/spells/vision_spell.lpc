// Vision spell.
// Mobydick, 11-3-92. If you didn't vote, you get what you deserve...

#include <mudlib.h>

inherit DAEMON ;

varargs int cast (string str, int obj) {

	object target ;
	int sp, cost, skill ;

	if (str=="NONE") {
		write ("Whose surroundings would you like to see?\n") ;
		return 1 ;
	}
	str = lower_case(str) ;
	target = find_player(str) ;
	if (!target) {
		write ("That person is not logged on.\n") ;
		return 1 ;
	}
// If obj==1, then the call came from an object, and we don't assess
// the spell point cost.
	if (obj!=1) {
		sp = this_player()->query("spell_points") ;
		skill = this_player()->query_skill("Divinations spells") ;
        	cost = 100/(skill+10) ;
        	if (sp<cost) {
                	write ("You haven't got enough spell points to cast it.\n") ;
                	return 1 ;
		}
        	this_player()->set ("spell_points", sp-cost) ;
	}
	this_player()->vision_cast(target) ;
	this_player()->improve_skill("Divinations spells", 5) ;
	return 1 ;
}
