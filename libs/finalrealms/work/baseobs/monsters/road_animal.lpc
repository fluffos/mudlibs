// Different kinds of animals... 

inherit "/obj/monster";

void setup() {
      set_race("monster");
      set_long("It's just an animal.\n");
      switch(random(6))
      {
        case 0:
         set_name("dog");
         add_alias("dog");
         set_main_plural("dogs");
         set_gender(0);
         set_level(1);
         break;
        case 1:
         set_name("boar");
         add_alias("boar");
         set_main_plural("boars");
         set_gender(0);
         set_level(1);
         break;
        case 2:
         set_name("deer");
         set_short("deer");
         add_alias("deer");
         set_main_plural("deer");
         set_gender(0);
         set_level(1);
         break;
        case 3:
         set_name("rabbit");
         set_short("a rabbit");
         add_alias("rabbit");
         set_main_plural("rabbit");
         set_gender(0);
         set_level(1);
         break;
        case 4:
         set_name("wasps");
         set_short("swarm of wasps");
         set_long("The swarm contains an enormous amount of insects.\n");
         add_alias("swarm");
         set_main_plural("wasp swarms");
         set_gender(0);
         set_level(1+random(3));
         set_max_hp(60);
         break;
        case 5:
         set_name("ox");
         set_short("ox");
         add_alias("ox");
         set_main_plural("oxes");
         set_gender(0);
         set_level(3+random(1));
         break;
         }
      set_wimpy(0);
      set_random_stats(6, 18);

} /* setup() */
