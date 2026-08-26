#include <std.h>
#define DEBUG 0
#define WEIGHT_PENALTY 5
#define INVIS_PENALTY 10
#define CAUGHT_PENALTY 15
#define CAUGHT_DELAY 150
#define INVIS_CHECK_DIE 25 //this should be changed to a stealth check

inherit DAEMON;

mapping initiate_thievery(object thief, object victim, object item) {
	mapping results = ([]);
	int thief_roll, victim_roll, disable_time;

	thief_roll = (thief->query_skill("thievery") * 4/5) + roll_dice(1,20);
	if(sizeof(thief->query_armour("torso"))) thief_roll += thief->skill_armor_mod(thief->query_armour("torso"));

	if(victim->query_invis() && !thief->detecting_invis()) thief_roll -= INVIS_PENALTY;
	if(objectp(item) && item->query_weight() >= WEIGHT_PENALTY) thief_roll -= (item->query_weight() / WEIGHT_PENALTY);

	//going to try a penalty to stealing if caught rather than a flat failure
	if(thief->get_static("caught") && time() - (int)((mapping)thief->get_static("caught"))[victim] < CAUGHT_DELAY) {
		if(DEBUG) tell_object(thief,"caught pentalty: "+CAUGHT_PENALTY);
		thief_roll -= CAUGHT_PENALTY;
	}

	victim_roll = (victim->query_skill("perception") * 4/5) + roll_dice(1,20);
	if(DEBUG) {
		tell_object(thief, "victim_roll: "+victim_roll);
		tell_object(thief, "thief_roll: "+thief_roll);
	}

	if(userp(victim)) {
		//disable is used to prevent instantly fleeing and from spamming the victim with success
		//there should be a check in all movement commands and pocket dimension entering
		disable_time = 1 + ((100 - thief_roll) / 10);
		disable_time = disable_time < 2 ? 2 : disable_time;
		disable_time = disable_time > 12 ? 12 : disable_time;
		thief->set_disable(disable_time, victim);
		if(DEBUG) tell_object(thief,"disable_time: "+disable_time);
	}

	results["thief_roll"] = thief_roll;
	results["victim_roll"] = victim_roll;
	results["disable_time"] = disable_time;

	return results;
}

//int check_caught(int roll, object target, int sLevel, object player, object ob){
int check_caught(int victim_roll, object victim, int thief_roll, object thief, object ob) {
	int test;
	int i;
	object *witnesses;
	int weight;
	int intox,vic_perc,thief_perc,condition,busy,bonus;
	string *pkills;

	vic_perc = (victim->query_intox()*100) / victim->query_formula();
	thief_perc = (thief->query_intox()*100) / thief->query_formula();
	if(DEBUG) tell_object(thief, "vic_perc: "+vic_perc);
	if(DEBUG) tell_object(thief, "thief_perc: "+thief_perc);

	intox = (vic_perc/10) - (thief_perc/10);
	if(DEBUG) tell_object(thief, "intox: "+intox);

	condition = (100 - (int)victim->query_condition_percent()) - (100 - (int)thief->query_condition_percent());
	if(DEBUG) tell_object(thief, "condition: "+condition);

	witnesses = all_living(environment(thief));
	witnesses = filter_array(witnesses, (:!(avatarp($1) && $1->query_true_invis()):));
	witnesses = filter_array(witnesses, (:!$1->query_property("spell_creature"):));
	busy = (5 * ( sizeof(witnesses) -2) ) - 10;
	if(DEBUG) tell_object(thief, "busy: "+busy);

	bonus = intox + condition + busy + thief_roll;
	test = 50 + ((int)victim->query_highest_level() - bonus);
	if(DEBUG) tell_object(thief, "bonus: "+bonus);
	if(DEBUG) tell_object(thief, "test: "+test);

	if ((100 - victim_roll) < test) {
		thief->set_hidden(0);
		if(thief->query_magic_hidden()) {
			if(thief->is_thief()) bonus = 5;
			else bonus = 0;
			if((int)victim->query_stats("wisdom") > (random(INVIS_CHECK_DIE) + bonus)) {
				thief->force_me("appear");
				thief->set_magic_hidden(0);
			}
		}

		tell_object(victim,"You catch "+thief->query_cap_name()+" with "+thief->query_possessive()+" hand in your pocket.\n");
		tell_object(thief,"You get caught.");
		tell_room(environment(thief),"You see "+victim->query_cap_name()+" catch "+thief->query_cap_name()+" with a hand in "+victim->query_possessive()+" pocket.",({thief,victim}));
		for(i=0;i<sizeof(witnesses);i++){
			if(objectp(witnesses[i])) witnesses[i]->check_caught(thief,victim,victim_roll);
		}

		if (!interactive(victim)) victim->kill_ob(thief,0);
		else log_file("player/theft", thief->query_name()+"("+thief->query_level()+") was caught stealing"+(objectp(ob) ? " "+ob->query_name() : "")+" from "+victim->query_name()+"("+victim->query_lowest_level()+") on "+ctime(time())+"\n");

		if(objectp(ob)) {
			if(ob->query_weight() < 1) weight = 1;
			else weight = ob->query_weight();
			if(environment(ob) == thief && (int)thief->query_stats("dexterity") < (random(20) + weight/10)) {
				thief->force_me("drop "+((string *)ob->query_id())[0]);
			}
		}

		thief->set_static("caught",([victim:time()]));
		thief->set_paralyzed(2,"You have been caught!");
		if(interactive(thief)) {
			pkills = thief->query_pkilled();
			if(member_array(victim->query_name(),pkills) == -1) {
				pkills += ({victim->query_name()});
				thief->set_pkilled(pkills);
			}
		}
	}
	return test;
}
