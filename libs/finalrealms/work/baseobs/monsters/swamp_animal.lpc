// Animals in the swamp...

inherit "/obj/monster";

void setup() {
         set_race("monster");
         set_long("It's just an animal.\n");
	 set_random_stats(6, 18);
         /* ob->set_wimpy(10); */
         switch(random(6))
         {
                case 0:
                 set_name("dog");
                 set_short("swamp dog");
                 add_adjective("swamp");
                 set_main_plural("dogs");
                 set_gender(0);
                 set_level(-1+random(2));
                 break;
                case 1:
                 set_name("boar");
                 set_short("wild boar");
                 add_adjective("wild");
                 set_main_plural("boars");
                 set_gender(0);
                 set_level(1+random(2));
                 break;
                case 2:
                 set_name("toad");
                 set_short("green toad");
                 add_adjective("green");
                 set_main_plural("toads");
                 set_gender(0);
                 set_level(-1+random(2));
                 break;
                case 3:
                 set_name("crawler");
                 set_short("carrion crawler");
                 add_adjective("carrion");
                 set_main_plural("carrion crawlers");
                 set_gender(0);
                 set_level(random(3));
                 break;
                case 4:
                 set_name("lamprey");
                 set_short("land lamprey");
                 set_long("It looks like a leech ending in a row of teeth.\n");
                 add_adjective("land");
                 set_main_plural("land lampreys");
                 set_gender(0);
                 set_level(1+random(3));
                 break;
                case 5:
                 set_name("leech");
                 set_short("giant leech");
                 add_adjective("giant");
                 set_main_plural("giant leeches");
                 set_gender(0);
                 set_level(2);
                 break;
         }

} /* setup() */
