// _backstab.c
// The backstab command. Lets a player who is not currently in
// combat try to make a sneak attack for extra damage.
// Uses the modifier hooks in execute_attack.c
// Based on an earlier version by Fudge@TMI-2
// This version by Mobydick@TMI-2

#include <mudlib.h>

inherit DAEMON ;

string help() ;

int cmd_backstab (string str) {

	object victim ;
	int pskill, hit_bonus, damage_bonus, chance ;

	if (!str) return write(help());
	victim = present(str,environment(this_player())) ;
	if (!victim) {
		notify_fail ("There's no one here by that name.\n") ;
		return 0 ;
	}
	if (!living(victim)) {
		notify_fail ("It will hardly help to attack that.\n") ;
		return 0 ;
	}
	if (victim==this_player()) {
notify_fail ("You'll probably notice yourself sneaking up on yourself.\n") ;
		return 0 ;
	}
	if (sizeof(this_player()->query_attackers())>0) {
		notify_fail ("You're too busy fighting!\n") ;
		return 0 ;
	}
	pskill = this_player()->query_skill("Stealth") ;
	chance = 20 + pskill*3 ;
	if (random(100)<chance) {
// Success!
		write ("You sneak up behind "+victim->query("cap_name")+
			" and attack!\n") ;
		tell_object(victim, "Without warning, "+this_player()->
			query("cap_name")+" attacks you from behind!\n") ;
		say ("Suddenly, "+this_player()->query("cap_name")+
			" attacks "+victim->query("cap_name")+
			" from behind!\n", victim) ;
		this_player()->kill_ob(victim, 1) ;
		hit_bonus = 30 + pskill*2 ;
		damage_bonus = 5+pskill/2 ;
		this_player()->execute_attack(hit_bonus,damage_bonus) ;
		victim->execute_attack() ;
	} else {
// Failure :(
		write ("You try to sneak up behind "+victim->query("cap_name")+
			"but "+subjective(victim->query("gender"))+
			"hears you coming and turns.\n") ;
		tell_object(victim,"You hear "+this_player()->query("cap_name")+
			"sneaking up behind you. "+subjective(this_player()->
			query("gender"))+" attacks you!\n") ;
		say (this_player()->query("cap_name")+" attacks "+
			victim->query("cap_name")+"!\n", victim) ;
		this_player()->kill_ob(victim, 1) ;
	}
	return 1 ;
}

string help() {
  return(@END
Syntax:  backstab <name>

If you haven't started fighting yet, you can try to sneak up behind your enemy
and backstab them for extra damage.
END
  );
}
