#include <std.h>
#include <vswamp.h>

inherit VIRTUALSERVER;

void create() {
  ::create();
  set_how_long(6);
  set_day_sentances( ({
      "Many trees poke up through the thick swamp.",
      "A large willow tree droops down into the water of the swamp.",
      "A mat of moss grows across the top of the water.",
      "Vines snake across the ground, twisting into many different shapes.",
      "The ground is uneven and muddy, making travel difficult.",
      "The knee-deep water bubbles with each footstep through it.",
      "Something can be seen swimming through the water.  Hopefully it's not dangerous.",
      "A thick haze seems to have settled on this area.",
      "The mist is so dense here that nothing can be seen beyond a few arm lengths.",
      "Nightshade is king!!!",
  }) );
/*  set_night_sentances( ({
      "This is the first night sentance.",
      "This is the second night sentance.",
      "This is the third night sentance."
  }) ); */
  set_item_list( ([
      "trees" : "A few trees seem to have survived this murky swamp.",
      "willow tree" : "The willow tree's branches are long and wilted, the tips dangling in the water.",
      "vines" : "The vines loop around trees and stumps, trying to stay above the water.",
      "water" : "The water comes up to your knees, and is too murky to see through.",
      ({"mist", "haze"}) : "This mist is so thick it could be cut with a dull scimitar."
  ]) );
  set_smell("A thick, rotting smell dulls the senses.");
  set_listen("Unseen crickets chirp in the distance.");
  set_reset_list( ({
      MOB"wmocc", MOB"dragonfly", MOB"toad", MOB"harpy"
  }) );
  set_properties( ([ "light" : 1,
                     "night light" : 1,
                     "swamp" : 1
                   ]) );
  set_short("Murky Swamp");
}
