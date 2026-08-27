// Snake...

inherit "/obj/monster";


void setup() {
         set_name("snake");
         set_short("snake");
         set_al(-30);
         set_main_plural("snakes");
         add_alias("worm");
	 set_random_stats(6, 18);
         set_race("snake");
         set_level(2+random(2));
         set_long("This is an agressive large snake.\n");
         set_aggressive(1);
         set_join_fight_mess("A snake slithers into the fight.\n");
         add_triggered_action("bing2", "event_death", this_object(), "death");
//         add_triggered_action("regen", "death", this_object(), "regen_after_death");

} /* setup() */
