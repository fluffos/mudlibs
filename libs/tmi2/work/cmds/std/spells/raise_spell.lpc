// Raise dead spell
// Mobydick, 11-23-92.

#include <mudlib.h>

inherit DAEMON ;

varargs int cast (string str, int obj) {

	object target, corpse ;
	int sp, cost, skill ;
	object env ;
	string corpse_id ;

	if (str=="NONE") {
		write ("Who to you wish to give life to?\n") ;
		return 1 ;
	}
	str = lower_case(str) ;
	corpse_id = "corpse of "+capitalize(str) ;
	env = environment(this_player()) ;
	corpse = present(corpse_id,env) ;
	if (!corpse) {
		write ("The "+corpse_id+" isn't here to cast it on.\n") ;
		return 1 ;
	}
	target = find_player(str) ;
	if (!target) {
		write ("That person is not logged on.\n") ;
		return 1 ;
	}
	if ((int)target->query("ghost")!=1) {
		write (capitalize(str)+" has already revived.\n") ;
		return 1 ;
	}
// if obj==1, then the call came from an object, and we don't assess
// the spell point cost.
	if (obj!=1) {
		sp = this_player()->query("spell_points") ;
		skill = this_player()->query_skill("Healing spells") ;
        	cost = 300/(skill+10) ;
        	if (sp<cost) {
                	write ("You haven't got enough spell points to cast it.\n") ;
                	return 1 ;
		}
        	this_player()->set ("spell_points", sp-cost) ;
	}
	tell_object (target, "Suddenly you are swept up by an invisible force!\n") ;
	target->set("_revive",1) ;
	target->force_me("_revive") ;
// The revive forces the player to change from a ghost object to a player
// object, so we have to find the new body.
	target = find_player(str) ;
	target->move(env) ;
	target->set("hit_points",1) ;
	corpse->remove() ;
	write ("You bring "+capitalize(str)+" back from the dead.\n") ;
	this_player()->improve_skill("Healing spells", 15) ;
	return 1 ;
}
