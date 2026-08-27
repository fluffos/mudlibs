
inherit "/obj/monster";



void setup()
  {
  set_name("spider");
  set_short("a huge spider");
  add_alias("spider");
  set_main_plural("spiders");
  set_gender(1);
  set_race("spider");
  set_random_stats(6,16); //will set radom between 6 & 18.. for all stats..
  set_level(random(2)+2); 
  set_al(0);
  add_triggered_action("bing2", "event_death", this_object(), "death");
  set_long("This is a huge spider. Wonder if it's poisonous.\n");
  set_wimpy(0);
  
  /* Money? maybe.. */
  //adjust_money(10, "silver");
} /* setup */
