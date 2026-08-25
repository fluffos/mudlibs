// Centipede...

inherit "/obj/monster";


void setup() {
         set_name("centipede");
         set_short("giant centipede");
         add_adjective("giant");
         add_adjective("black");
         set_main_plural("centipedes");
	 set_random_stats(6, 18);
         add_move_zone("forest");
         set_long("A giant black centipede.\n");
         set_aggressive(1);
         set_join_fight_mess("An centipede gleefully throws itself into combat.\n");
         add_triggered_action("bing2", "event_death", this_object(), "death");
         set_race("snake");
         set_level(1+random(2));
         set_wimpy(0);

} /* setup() */
