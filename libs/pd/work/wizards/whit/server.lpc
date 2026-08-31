#include <std.h>
#include <tundra.h>
inherit VIRTUALSERVER;
void create() {
  ::create();
  set_how_long(6);
  set_day_sentances( ({
      "The icy tundra has made it very hard for many animals to live.",
      "A high pitched squeak can be heard as the snow crunches underfoot.",
      "Howling winds make seeing and hearing almost impossible.",
      "Small animal tracks lead off the path in different directions.",
      "The mournful sound of a wolf's howl can be heard in the distance.",
      "Oh yuck! whats that on the side of the path?",
      "Some of the hardier underbrush has grown up along the side of the path.",
      "The fuzzy images of a city can be seen to the north.",
      "The flat icy wasteland stretches out in every direction, giving the impression that there is nothing to be found that cant be seen.",
      "A skeleton of a rather large animal rests off in the distance, picked clean by hungry predators.",
      "Small marks have been carved in the wood of a small tree, they are too faint to make out.",
      "Not many people have ventured this far into a tundra and survived.",
      "Snowdrifts line the path, gathered up on the small rocks placed there by other travelers.",
      "A tiny field mouse pokes its head out from its hiding place to see who is passing by.",
      "The remains of some kind of rodent are decaying near the path.",
      "Penguins chatter at one another off in the distance.",
      "A mound of dirt near the path looks to be freshly dug.",
      "The cairn of some unfortunate traveler rests some distance away from the path.",
      "Penguins play with each other off in the distance, oblivous to the cold.",
      "A small stump lies in the middle of the path to trip unwary travelers.",
       
      
  }) );
  set_night_sentances( ({
      "The darkness of night makes traversing the path dangerous.",
      "Small footsteps can be heard out of sight.",
      "The temptature has dropped well below freezing.",
      "The scuttling and scurrying of the night creatures echos through the silent night as they wake up to begin their hunts.",
      "A howl off in the distance sends nearby animals scurrying to their burrows.",
      "The moon hangs large above the horizion, bathing the landscape in an eerie light blue color.",
      "Small fires can be seen far far in the distance as other travelers stop for the night.",
      "Growling rumbles in through the night as an animal runs past the path.",
      "The lack of light down the path gives a distinct feeling of danger and trepidation.",
      "The darkness shrouds everything in shadow, creating a sense of doom and despair.",
      "A sense of being watched seems to eminate from the shadows.",
      "Shadowy forms out in the tundra seem to creep closer to the path.",
      "Howling noises accompany the wind each time it blows.",
      "Rough uneven ground makes travelling at night treacherous.",
      
  }) ); 
  set_item_list( ([
      "path" : "A well worn footpath made by many travelers.",
      ({"shadow", "shadows"}) : "Shadowy figures too far away to see.",
      "mound" : "A pile of dirt.",
      ({"grass", "grasses"}) : "There is only a sparce amount of grass that has managed to survive the cold.",
      "field mouse" : "Small rodentlike animals that live in the tundrat.",
      "stump" : "The base of a small tree, the top portion long gone.",
      "skeleton" : "these bones are all that is left of a once great elk.",
      "tracks" : "Large feline tracks.",
      "foilage" : "Just a lite sprinkling of grass here and there.",
      "remains" : "A rotting corpse of a rodent.",
      "underbrush" : "Small bushes, large weeds, and other kinds of plants have grown together in unpassable clumps.",
      "shapes" : "Fuzzy outlines that could be human or not.....",
      "cairn" : "It looks like it has been here for years, moss has grown up around the rocks.",
  ]) );
  set_smell("The cold is too harsh to smell anything");
  set_listen("The gusting wind is sometimes broken by a mournful howl.");
  set_reset_list( ({
      MOB"penguin", MOB"lynx", MOB"articbear", MOB"snowfox", MOB"caribou", MOB"moose", MOB"falcon",
      MOB"foxcub", MOB"leopardcup", MOB"mouse", MOB"snowrabbit", MOB"snowleopard",
      MOB"mink", MOB"seal", MOB"sealpup",
  }) );
  set_properties( ([ "light" : 1,
                     "night light" : 0,
                     "forest" : 1
                   ]) );
  set_short("A tundra wasteland.");
}
