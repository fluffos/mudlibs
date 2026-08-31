#include <std.h>
#include <pgraveyard.h>
inherit VIRTUALSERVER;
void create() {
  ::create();
  set_how_long(4);
  set_day_sentances( ({
      "Headstones line the path like watchful guardians.",
      "Leaves crunch underfoot from the horrible upkeep provided.",
      "Howling winds make it sound like the dead are trying to speak.",
      "Ancient gnarled trees sprout from the ground.",
      "The mournful sound of a wolf's howl can be heard in the distance.",
      "Shadowy shapes move between the trees in this part of the graveyard.",
      "The creepy feeling of being watched hovers over the area.",
      "The fuzzy images of a city can be seen to the northwest.",
      "Flowers, dead for quite a while, lie against the base of a few headstones.",
      "The smell of fresh dirt drifts through the air from a newly dug grave.",
      "Small marks have been carved in the headstone of some unknown person, they are too faint to make out.",
      "Death lets its presence be known as travelers walk through this sanctuaray of the dead.",
      "Ghosts wander around this field of the dead at random, crawling up from their graves to torment the living.",
      "The wispers of wars long past flow through this land like a quiet stream.",
      "A lonely soul wanders this part of the graveyards, hoping to catch a person who can listen to them.",
      "Old weeping willows and mossy oaks, bent with age, guard the homes of the dead dug beneath their outstretched limbs.",
      "Owls who in the trees, picking out the next unlucky traveler that will wind up in the earth below.",
      "The cairn of some unfortunate traveler lays above the ground, his fellows didnt have the time to bury him.",
      "Old monuments of the dead long past throw their shadows from far away in the graveyard.",
      "A small stump lies in the middle of the path to trip unwary travelers.",
       
      
  }) );
  set_night_sentances( ({
      "The graveyard seems even spookier at night with the rare owl whooting off in the distance calling for the dead.",
      "Tombstones have taken an eerie shine, as if they possess some strange energy.",
      "Sounds of battles long ago rise from the darkness as the ghosts are forced to reinact their demise.",
      "A sense of being followed fills the room with an oppressive quality.",
      "Small red eyes peer out at travelers as they cross through the graveyards.",
      "The screams of tortured souls echos throughout the land.",
      "A stench of death belches forth from the graves as the dead rise to fight again.",
      "Clanking of ancient armour and outdated weapons reverberates off the trees and tombstones.",
      "Insanity and madness rule throughout the night as the ghosts and spirits wage a war in the other realms.",
      "The darkness of night makes traversing the path dangerous.",
      "Small footsteps can be heard out of sight.",
      "The temptature has dropped well below freezing, making it hard to breathe.",
      "The scuttling and scurrying of nokturnl creatures echos through the silent night as they wake up to begin their hunts.",
      "A howl off in the distance sends nearby animals scurrying to their burrows.",
      "The moon hangs large above the horizion, bathing the landscape in an eerie light blue color.",
      "Small fires can be seen far far in the distance as other travelers stop for the night.",
      "Growling rumbles in through the night as an animal runs past the path.",
      "The lack of light down the path gives a distinct feeling of danger and trepidation.",
      "The darkness shrouds everything in shadow, creating a sense of doom and despair.",
      "A sense of being watched seems to eminate from the shadows.",
      "Shadowy forms seem to reach out for unsuspectin travelers.",
      "The moans of the dead start to emerge throughout the night.",
      "Little enough light makes traveling in the graveyards a dangerous proposition.",
      
  }) ); 
  set_item_list( ([
      "ghosts" : "Long dead warrior and polititions war with each other in the beyond.",
      "path" : "An aged and worn path made from the feet of many mourners.",
      ({"shadow", "shadows"}) : "Shadowy figures too far away to see.",
      "cairn" : "A pile of rocks stacked neatly over a body to keep the predators at bay.",
      ({"grass", "grasses"}) : "A lawn grown out of control from lack of care.",
      "stump" : "The base of a small tree, the top portion long gone.",
      "darkness" : "An eerie kind of darkness, how could that have come along in the middle of the day?",
      "tracks" : "You cant tell what made these tracks.",
      "foilage" : "Just a lite sprinkling of grass here and there.",
      "underbrush" : "Small bushes, large weeds, and other kinds of plants have grown together in unpassable clumps.",
      "shapes" : "Fuzzy outlines that could be human or not.....",
  ]) );
  set_smell("Death hangs in the air....");
  set_listen("Moaning and groaning drift about from grave to grave.");
  set_reset_list( ({
      MOB"soldierghost", MOB"generalghost", MOB"pageghost", MOB"calvaryghost",
      MOB"crow", MOB"cockroach", MOB"rat", MOB"owl", MOB"barnowl",
      MOB"majorskeleton", MOB"skeletoncorporal", MOB"caretaker",
  }) );
  set_properties( ([ "plains" : 1,
                     "light" : 1,
                     "night light" : 0,
                   ]) );
  set_short("A desolate graveyard.");
}
