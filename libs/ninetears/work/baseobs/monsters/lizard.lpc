// Lizard...

inherit "/obj/monster";

void setup() {
       set_name("lizard");
       set_short("giant lizard");
       set_race("lizard");
       set_level(3+random(5));
       set_wimpy(0);
       add_alias("reptile");
       set_random_stats(6, 18);
       add_adjective("giant");
       add_adjective("green");
       set_long("The giant lizard looks hungry. It has green scales.\n");
       load_chat(10,({1, ":crawls around.\n"}));
       load_a_chat(50,({1, ":bashes you with its tail.\n"}));
       set_join_fight_mess("A lizard smells the blood of the fight and attacks.\n");
       load_chat(10,
         ({
                1, "'Grrrrrr!",
                1, ":bares it's teeth.",
                1, ":growls menacingly.",
         }));

} /* setup() */
