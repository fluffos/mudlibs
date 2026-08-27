inherit "/obj/monster";


void setup()
  {
     set_name("bear");
     set_al(30);
     set_short("black bear");
     add_alias("bear");
     add_adjective("black");
     set_main_plural("black bears");
     set_long("It's one of those black bears that are so common.\n");
     set_join_fight_mess("A bear bounces into the combat fray.\n");
     add_triggered_action("bing2", "event_death", this_object(), "death");
     set_race("bear");
     set_level(3+random(2));
     set_wimpy(0);
     set_random_stats(6,18);
     set_gender(random(2)+1);

}


