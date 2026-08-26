// Message spell.
// Mobydick, 11-18-92.
// Part of the good old MudOS mudlib. Please leave this header on.

#include <mudlib.h>

inherit DAEMON ;

varargs int cast (string str, int obj) {

	object target ;
	int sp, cost, skill ;

	if (str=="NONE") {
		write ("To whom do you wish to send a message?\n") ;
		return 1 ;
	}
	str = lower_case(str) ;
	target = find_player(str) ;
	if (!target) {
		write ("That person is not logged on.\n") ;
		return 1 ;
	}
// If obj==1, then the spell call came from an object and we do not want
// to assess the spell points cost.
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
	this_player()->message_cast(target) ;
	this_player()->improve_skill("Divinations spells", 5) ;
	return 1 ;
}
