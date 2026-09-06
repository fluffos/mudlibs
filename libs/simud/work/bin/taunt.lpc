/**
 * Note: Insults and comebacks liberally stolen from Monkey Island.
 */

string *insults;
string *comebacks;

string *query_insults() { return insults; }
string *query_comebacks() { return comebacks; }
string query_insult(int x) { return insults[x]; }
string query_comeback(int x) { return comebacks[x]; }

void create() {
	insults = ({
		// Monkey Island 1
		"This is the END for you, you gutter-crawling cur!",
		"My handkerchief will wipe up your blood!",
		"I once owned a dog that was smarter than you.",
		"You make me want to puke.",
		"You fight like a dairy farmer.",
		"There are no words for how disgusting you are.",
		"Have you stopped wearing diapers yet?",
		"You're no match for my brains, you poor fool.",
		// Monkey Island 3
	});
	comebacks = ({
		// Monkey Island 1
		"And I've got a little TIP for you, get the POINT?",
		"So you got that job as a janitor after all.",
		"He must have taught you everything you know.",
		"You make me think somebody already did.",
		"How appropriate. You fight like a cow.",
		"Yes there are. You just never learned them.",
		"Why, did you want to borrow one?",
		"I'd be in real trouble if you ever used them.",
		// Monkey Island 3
	});
}

void practice_taunt( object who, string type, int number ) {
	string *k_list = who->query_env_var("known_"+type+"s");
	mapping l_list = who->query_env_var("learning_"+type+"s");
	if( !pointerp(k_list) )
		k_list = ({});
	if( member(k_list, number) != -1 )
		return;
	if( !mappingp(l_list) )
		l_list = ([ number: 1 ]);
	else
		l_list[number]++;
	if( l_list[number] >= 3 * sizeof(k_list) ) {
		msg_object(who, "~CTITYou have learned a new "+type+"!~CDEF");
		l_list -= ([ number ]);
		k_list += ({ number });
		who->set_env_var("known_"+type+"s", k_list);
	}
	who->set_env_var("learning_"+type+"s", l_list);
}

/**
 * Actually perform the taunt. Separated so it can potentially be used elsewhere.
 */
void do_taunt( object actor, object victim ) {
	int i_num, c_num, *i_list, *c_list;
	object who;
	// select an insult at random
	if( i_list = actor->query_env_var("known_insults") )
		i_num = i_list[random(sizeof(i_list))];
	else {
		i_num = random(sizeof(insults));
		practice_taunt( actor, "insult", i_num );
	}
	// select a comeback
	if( c_list = victim->query_env_var("known_comebacks") ) {
		if( member(c_list, i_num) != -1 )
			c_num = i_num;
		else
			c_num = c_list[random(sizeof(c_list))];
	} else {
		c_num = random(sizeof(comebacks));
		practice_taunt( victim, "comeback", c_num );
	}
	// spit them out ;)
	set_target(victim);
	set_actor(actor);
	actor->msg_local("~CEMO~Name ~verbtaunt ~targ: ~CDEF"+insults[i_num]);
	// TODO: only let intelligent targets respond
	if( i_num == c_num )
		victim->msg_local("~CEMO~Subt casually ~vertreply: ~CDEF"+comebacks[c_num]);
	else {
		object *queue = victim->query_targets();
		if( !queue )
			queue = ({ actor });
		else {
			queue -= ({ actor });
			queue = ({ actor }) + queue;	
		}
		victim->msg_local("~CEMO~Subt weakly ~vertrespond: ~CDEF"+comebacks[c_num]);
		victim->set_targets( queue );
		victim->start_combat( actor );
	}
	// teach people insults and stuff
	practice_taunt( actor, "comeback", c_num );
	practice_taunt( victim, "insult", i_num );
	foreach( who : all_inventory(environment(actor)) ) {
		if( !who->query_is_living() )
			continue;
		practice_taunt( who, "insult", i_num );
		practice_taunt( who, "comeback", c_num );
	}
}

int main(string arg) {
	object who;
	if( !arg )
		who = this_player()->query_target();
	else
		who = single_present(arg, environment(this_player()));

	if( !who || !who->query_is_living() )
		return notify_fail("What do you want to taunt?\n");
	if( who == this_player() )
		return notify_fail("Haha. Very funny.\n");
	if( this_player()->query_endurance() < 5 )
		return notify_fail("You don't have enough endurance to yell a good taunt.\n");
	if( who->query_target() == this_player() )
		return notify_fail("You already have their attention, better save your breath.\n");

	this_player()->add_readiness( -100 );
	this_player()->add_endurance( -5 );
	do_taunt( this_player(), who );
	return 1;
}
