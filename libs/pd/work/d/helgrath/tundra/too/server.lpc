#include <std.h>
#include <tundratoo.h>
inherit VIRTUALSERVER;
void create() {
  ::create();
  set_how_long(6);
  set_day_sentances( ({
      "Howling winds make seeing and hearing almost impossible.",
      "Small animal tracks lead off the path in different directions.",
      "The mournful sound of a wolf's howl can be heard in the distance.",
      "The cold here is enough to numb unprotected extremities.",
      "A few of the trees have snow piled upon thier branchs."
      "Some of the hardier underbrush has grown up along the side of the path.",
      "An open tundra is to the north devoid of trees.",
      "Small marks have been carved in the wood of a small tree, they are too faint to make out.",
      "A thick forest to the south marks the end of the tundra.",
      "Snowdrifts line the path, gathered up on the small rocks placed there by other travelers.",
      "A tiny field mouse pokes its head out from its hiding place to see who is passing by.",
      "The remains of some kind of rodent are decaying near the path.",
      "A mound of dirt near the path looks to be freshly dug.",
      "The cairn of some unfortunate traveler rests some distance away from the path.",
      "Sparce trees litter the area.",
       
      
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
      "Shadowy forms out among the trees seem to creep closer to the path.",
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
      MOB"lynx", MOB"snowfox", MOB"moose", MOB"falcon",
      MOB"foxcub", MOB"leopardcub", MOB"snowrabbit", MOB"snowleopard",
      MOB"mink"
  }) );
  set_properties( ([ "forest" : 1,
                     "light" : 1,
                     "night light" : 0,
                   ]) );
  set_short("A sparcely treed tundra.");
}
