// Crocodile

inherit "/obj/monster";


void setup() {
         set_name("crocodile");
         add_alias("reptile");
         add_adjective("green");
         add_adjective("large");
         set_short("crocodile");
         set_main_plural("crocodiles");
         set_race("reptile");
         set_level(5+random(3));
         set_random_stats(6, 18);
         set_long("This is a large green crocodile.\n");
         load_chat(10,
         ({
                1, ":crawls away from you.",
                1, ":opens it's mouth and heads in your direction.",
                1, ":strethes lazily in the sun.",
                1, ":relaxes back into the water.",
                1, "@yawn boredly",
         }));
         add_triggered_action("bing2", "event_death", this_object(), "death");
         // ob->add_attack("bash", 0, 20, 100, -20, 0, "blunt");

} /* setup() */
