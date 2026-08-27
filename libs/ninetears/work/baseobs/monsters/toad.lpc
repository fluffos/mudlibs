// Toad...

inherit "/obj/monster";


void setup() {
         set_name("toad");
         add_adjective("ugly");
         set_race("reptile");
         set_al(60);
	 set_random_stats(6, 18);
         set_aggressive(1);
         set_level(1+random(2));
         set_short("giant toad");
         set_main_plural("giant toads");
         add_plural("toads");
         set_join_fight_mess("A giant toad joins the fight.\n");
         add_triggered_action("bing2", "event_death", this_object(), "death");
         set_long("It's a a giant aggressive toad.\n");
         load_a_chat(30,
         ({
                1, ":slaps you with its tongue."
         }));

} /* setup */
