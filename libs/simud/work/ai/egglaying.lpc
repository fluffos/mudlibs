inherit "/ai/module";

string query_module_name() { return "egglaying"; }

#define HOUR	3600

int query_last_egg() { return environment()->query_env_var("last_egg"); }
void set_last_egg(int x) { environment()->set_env_var("last_egg",x); }
int query_fertile() { return environment()->query_env_var("fertile"); }
void set_fertile(int x) { environment()->set_env_var("fertile",x); }
int query_birth() { return environment()->query_env_var("birth"); }
void set_birth(int x) { environment()->set_env_var("birth",x); }

void on_sight(object ob, object src) {
	if( environment() == ob ) return;

	if( environment()->query_env_var("fertile") ) return;
	
	if( ob->query_file_name() != environment()->query_file_name() )
		return;
	
	if( ob->query_gender() == 1 &&
		environment()->query_gender() == 2 ) {
			debug("female saw a male, impregnating", "ai");
			environment()->set_env_var("fertile",1);
			command("emote quacks loudly.",environment());
	}
}

void on_tick() {
	int foodp, drinkp;
	object nest;
	if( !query_enabled() ) return;
	// only females lay eggs
	if( environment()->query_gender() == 1 ) {	// male
		disable();
		return;
	}
	// young hens don't lay eggs	
	if( !query_birth() ) {
		set_birth( time() );
		return;
	} else if( time() - query_birth() < HOUR ) {
		return;
	}

	//debug(time() - query_birth(),"ai");
	
	// Am I hungry?
	foodp = environment()->query_food() * 100 / environment()->query_food_capacity();
	drinkp = environment()->query_drink() * 100 / environment()->query_drink_capacity();

	//debug("tick. "+foodp+"/"+drinkp,"ai");

	if( random(100) < 20 )
		command("emote quacks.", environment());
	else if( random(100) < 30 )
		command("walk random", environment());
	
	// If I am in good condition and there is a nest here, lay
	if( foodp > 75 && drinkp > 75 &&
		nest = present_clone("/scn/nest", environment(environment())) ) {
		
		object egg = clone_object("/items/food/egg");
		egg->set_product_aspect( environment()->query_product_aspect() );
		egg->move( nest );
		if( query_fertile() && time() - query_last_egg() < HOUR ) {
			egg->set_fertile( 1 );
			set_fertile( 0 );
			set_last_egg( time() );
		}

		command("emote lays an egg.", environment());
		environment()->add_food(-100);
		environment()->add_drink(-100);

		debug("laid an egg into "+as_lpc(nest),"ai");
	}
}
