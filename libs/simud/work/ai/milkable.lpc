inherit "/ai/module";

string query_module_name() { return "milkable"; }

int query_milk() { return environment()->query_env_var("milk"); }
void set_milk(int x) { environment()->set_env_var("milk",x); }
void add_milk(int x) { set_milk(query_milk() + x); }

void on_tick() {
	int foodp, drinkp;
	if( !query_enabled() ) return;

	// Am I hungry?
	foodp = environment()->query_food() * 100 / environment()->query_food_capacity();
	drinkp = environment()->query_drink() * 100 / environment()->query_drink_capacity();

	//debug("tick. "+foodp+"/"+drinkp+", "+query_milk(),"ai");
	
	// Am I full of milk?
	if( query_milk() >= environment()->query_stat("con") ) {
		if( random(100) < 25 )
			command("emote moos uncomfortably.", environment());
	  	return;
	}


	// produce milk if i am not hungry
	if( foodp > 50 && drinkp > 50 ) {
		command("emote moos contentedly.", environment());
		environment()->add_food(-100);
		environment()->add_drink(-100);
		add_milk(1);
		debug("generated milk","ai");
	}
}
