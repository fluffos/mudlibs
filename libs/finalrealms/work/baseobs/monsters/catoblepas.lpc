// Catoblepas...in the swamp...

inherit "/obj/monster";


void setup() {
         set_name("catoblepas");
         add_adjective("large");
         set_race("monster");
       //set_class("fighter");
         set_al(100);
	 set_random_stats(6, 18);
         set_level(7+random(6));
         set_wimpy(0);
         set_short("a catoblepas");
         set_main_plural("catoblepases");
         set_join_fight_mess("Hearing sounds the catoblepas "
                "lumbers into the fray.\n");
         add_triggered_action("bing2", "event_death", this_object(), "death");
         set_long("The catoblepas walks with it's head raking the ground, "
          "so it probably can't see you with all the vegetation here. This is "
          "a good thing, for rumor goes it can kill you simply by looking at "
          "you. If you attack it just might raise its head.\n");
         load_chat(10,
         ({
          1, ":raises its head slightly, but the neck is luckily to weak.",
          1, ":walks around with its head held low.",
         }));
         load_a_chat(30,
         ({
          1, ":strikes you with its tail.",
          1, ":raises its head slightly trying to get a glimpse of you.",
         }));
         // ob->add_attack("gaze", 0 , 1, 3000, 0, 0, "magic");

} /* setup() */
