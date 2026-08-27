// Alligator...

inherit "/obj/monster";


void setup() {
         set_name("alligator");
         set_al(0);
         set_short("alligator");
         add_alias("reptile");
         add_adjective("aggressive");
	 set_random_stats(6, 18);
         set_main_plural("alligators");
         set_long("This is an aggressive repile called an alligator.\n");
         set_aggressive(1);
         set_join_fight_mess("A alligator crawls into the combat fray.\n");
         add_triggered_action("bing2", "event_death", this_object(), "death");
         set_race("reptile");
         set_level(4+random(4));

} /* setup */
