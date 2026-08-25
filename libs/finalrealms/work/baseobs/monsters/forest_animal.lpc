
inherit "/obj/monster";


void setup()
  {
  set_race("monster");
  switch(random(6))
  {
    case 0:
      set_name("dog");
      set_short("forest dog");
      add_adjective("forest");
      set_main_plural("dogs");
      set_gender(0);
      set_level(1);
      break;
    case 1:
      set_name("boar");
      set_short("wild boar");
      add_adjective("wild");
      set_main_plural("boars");
      set_gender(0);
      set_level(random(6)+3);
      break;
    case 2:
      set_name("deer");
      set_short("deer");
      set_main_plural("deer");
      set_gender(0);
      set_level(1);
      break;
    case 3:
      set_name("crawler");
      set_short("carrion crawler");
      add_adjective("carrion");
      set_main_plural("carrion crawlers");
      set_gender(0);
      set_level(random(3)+2);
      break;
    case 4:
      set_name("skunk");
      set_short("skunk");
      set_long("It looks very cute with its black'n white pelt.\n");
      add_adjective("cute");
      set_main_plural("skunks");
      set_gender(0);
      set_level(1);
      break;
    case 5:
      set_name("stag");
      set_short("mighty stag");
      add_adjective("mighty");
      set_main_plural("mighty stags");
      set_gender(1);
      set_level(random(2)+3);
      break;
  }
  set_random_stats(6,18); //will set radom between 6 & 18.. for all stats..
  set_al(0);
  set_wimpy(0);
  set_long("Just an ordinary animal.\n");
  /* Money? maybe.. */
  //adjust_money(10, "silver");
} /* setup */
