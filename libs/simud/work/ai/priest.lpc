inherit "/ai/module";

string query_module_name() { return "priest"; }

void on_tick() {
	object priest = environment();
	object room = environment(priest);
	object target;

	foreach( target : all_inventory(room) ) {
		if( !target->query_is_living() )
			continue;
		if( target->query_hp() * 100 / target->query_max_hp() < 75 )
			command( "cast heal on "+target->query_name(), priest );
		if( target->query_endurance() * 100 / target->query_max_endurance() < 50 )
			command( "cast invigorate on "+target->query_name(), priest );
		if( target->query_mana() * 100 / target->query_max_hp() < 50 )
			command( "cast channel on "+target->query_name(), priest );
	}
	command( "meditate", priest );
}
