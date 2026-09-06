inherit "/ai/module";

string query_module_name() {
	return "assist";
}

void on_fight( object attacker, object victim ) {
	object *friends = ({}), ob;
	if( attacker == victim || attacker == environment() || victim == environment() )
		return;
	debug("on_fight: "+attacker->query_name()+", "+victim->query_name(),"combat");

	// currently, party members are poorly defined, so we will just use their
	// master from the worker module
	ob = present_clone("/ai/worker",environment());
	if( ob )
		friends += ({ find_player(ob->query_master()) });


	// if a party member attacks, attack their victim
	if( member(friends, attacker) != -1 )
		command("kill "+victim->query_name(),environment());
	// if a party member is attacked, attack the aggressor
	if( member(friends, victim) != -1 )
		command("kill "+attacker->query_name(),environment());
}
