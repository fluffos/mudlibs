// Rat...

inherit "/obj/monster";

void setup() {    
      set_name("rat");
      set_short("rat");
      set_race("rat");
      add_move_zone("city");
      set_level(-5);
	set_random_stats(3, 13);
      add_alias("city rat");
      add_adjective("dirty");
      add_adjective("city");
      set_long(
"This is a large rat.  It appears to have done well living in the city.\n"+
"The pollution must not affect it to much.\n");
      load_chat(10,({1, "The rat squeaks.\n"}));
      load_a_chat(50,({1, "The rat squeels in pain.\n"}));
//      add_triggered_action("regen", "death",  this_object(), "regen_after_death");
} /* setup */
