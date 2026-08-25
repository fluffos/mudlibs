// Original by Moloch. additional animals added by Cadogan
inherit "/obj/monster";

void setup()
  {
  set_race("monster");
  switch(random(9))
  {
    case 0:
      set_name("dog");
      set_short("forest dog");
      add_adjective("forest");
      set_main_plural("dogs");
      set_long("The feral dog is one of the almost-wolves roaming the Realms "+
           "in search of food. It has the lean, half-starved look that tells "+
           "you it hasn't had much luck lately.\n");
      set_gender(0);
      set_level(3+random(5));
      break;
    case 1:
      set_name("boar");
      set_short("wild boar");
      add_adjective("wild");
      set_main_plural("boars");
      set_gender(0);
      set_long("The boar is 600 pounds of barely supressed animal rage.  "+
     "It has large tusks that leave no doubt that these creatures are "+
    "predators of a kind - and the mad look in its eyes warns you not to "+
    "make any sudden moves.\n");
      set_level(7+random(4));
      break;
    case 2:
      set_name("deer");
      set_short("deer");
      set_main_plural("deer");
      set_gender(0);
    set_long("The deer has light brown fur, slender-looking limbs, and large,"+
       "liquid eyes. It looks nervously at you, and dances skittishly away "+
    "when you come too close.\n");
      set_level(7);
      set_wimpy(50);
      break;
    case 3:
      set_name("crawler");
      set_short("carrion crawler");
      add_adjective("carrion");
      set_main_plural("crawlers");
      set_gender(0);
      set_long("The crawler is a large, insectoid carrion eater, "
         "first cousin to the carrion crawlers of the Underdark.\n");
      set_level(random(3)+2);
      break;
    case 4:
      set_name("skunk");
      set_short("skunk");
      set_long("It looks very cute with its black'n white pelt.\n");
      add_adjective("cute");
      set_main_plural("skunks");
      set_gender(0);
      set_level(10);
      break;
    case 5:
      set_name("stag");
      set_short("mighty stag");
      add_adjective("mighty");
      set_main_plural("stags");
      set_gender(1);
      set_long("The noble stag stands in repose, gazing calmly and without "+
    "fear at you.\n");
      set_level(5+random(5));
      break;
    case 6:
      set_name("rabbit");
      set_short("rabbit");
      add_adjective("furry");
      set_main_plural("rabbits");
      set_gender(1);
      set_long("This is an adorable little bunny rabbit.  He has a "
         "fluffy white tail and big floppy ears.\n");
      set_level(2+random(5));
      break;
    case 7:
      set_name("squirrel");
      set_short("squirrel");
      set_main_plural("squirrels");
      set_gender(1);
      set_long("This cute, fuzzy little squirrel is busy gathering nuts "
         "for a winter that will never come to Unicorn Mountain.\n");
      set_level(3+random(3));
      break;
    case 8:
      set_name("bird");
      set_short("colourful bird");
      add_adjective("colourful");
      set_main_plural("birds");
      set_gender(2);
      set_long("These brightly coloured birds dart in and out of the "
          "trees and bushes searching for berries to eat.\n");
      set_level(4+random(3));
      break;
 
  }
  set_random_stats(6,18); //will set random between 6 & 18 for all stats.
  set_al(-500);
} /* setup */
