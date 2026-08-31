#include <std.h>
#include <marshserver.h>
inherit VIRTUALSERVER;
void create() {
  ::create();
  set_how_long(4);
  set_day_sentances( ({
   "The murky water is putrid and foul smelling.",
   "Thick moss hangs from a nearby tree, giving it the look of some beast.",
   "Something screams off in the distance causing the area to become quiet.",
   "Low braches touch the water in their never ending battle for sunlight.",
   "The sounds of bugs buzzing off in the distance is overwhelming.",
   "Something swimming in the water leaves a wake of ripples behind it off "
   "in the distance.",
   "Mudbugs forage the area for food and other materials.",
   "The nearby trees are overgrown with moss causing them to droop.",
   "The sounds of a struggle echo from somewhere near by.",
   "Trees are sparsely scattered across the swampy water.",
   "A low fog hangs in the air, weighing heavily on everything it touches.",
   "Mosquitoes skim across the cloudy water.",
   "The image of an old woman appears in a cluster of trees.",
   "A low riding fog drifts by, before it dissipated into thin air.",
   "Mud clings to everything, drying into a hardened shell.",
   "A low tide washes over some fallen trees.",
   "Dead twigs float on top of the murky water.",
   "A school of fish swim by being chased by an oversized shadow.",  
   "A small snake slithers past.",
   "Mud swirls in the murkey water.",
   "The dampness of the fog sends chills down the spine.",
   "A frog sitting on a fallen log, snatches a fly.",
   "The fog changes everything to a dull color of grey.",
   "A weak current can be felt.",
  }) );

  set_night_sentances( ({
   "Trees are sparsely scattered across the swampy water.",
   "A low fog hangs in the air, weighing heavily on everything it touches.",
   "In a distance, ripples appear in the water.",
   "Mosquitoes skim across the cloudy water.",
   "The image of an old woman appears in a cluster of trees.",
   "A slight movement quickly shifts from tree to tree.",
   "Red beady eyes move in closer at a slow steady pace.",
   "A bat flies overhead and vanishes into the darkness.",
   "A rolling mist slowly sets in, vanishing everything in sight.",
   "A dead twig floats by and gets caught by long grass in the area.",
   "The outer rings of a ripple slowly fades away in the darkness.",
   "Thick moss hangs from a nearby tree giving it the look of some beast.",
   "Something screams off in the distance causing the area to become quiet.",
   "The sounds of bugs buzzing off in the distance is overwhelming.",
   "A long snake is swimming in the water, sending a wake of ripples behind "
   "it.",
   "Mudbugs forage the area for food and other materials.",
   "The nearby trees are overgrown with moss causing them to droop.",
   "The sounds of a struggle echo from somewhere near by.",
   "The moons' refections shimmers in the murkey water.",
   "The stars twinkle dimly through the heavy mist.",
   "The night air is cool and still.",
  }) ); 

  set_item_list( ([
        "marsh" : "Swamp land covered in a brackish water.",
        "trees" : "trees scatter the landscape, some lush and other sickly.",
        "mud"   : "Sticky foul mud that sticks to everything.",
        "water" : "Foul smelling putrid water, it is mostly useless.",
        "fog"   : "A dense low cloud of mist.",
        "ripples"   : "The trail left by something assing in the water.",
        "image" : "It was a quick movement but it was long enough to notice "
                 "an old woman.",
        "woman" : "She might have looked haggard but it was only a quick "
                 "glimpse.",
        "moss"  : "It grows on everything.",
        "branches" : "Tree branches.",
        "eyes"  : "The eyes poke up out of the murky water.",
        "mudbug"   : "They are everywhere moving around gathering food and "
                     "other materials.",
        "bugs" : "The marsh is filled with all manner of bugs.",
        "mosquitoes" : "In this stagnant water they thrive.",
        "mist"   : "The mist is cold and thick.",
        "twig" : "Small twig floating in the water.",
        "grass" : "Tall grass growing in the marsh.",
        "fish"   : "Sickly looking pale fish.",
  ]) );

    set_smell("It smells like wet soil after a day's rain.");
    set_listen("Sounds of creatures splashing in a distance");

  set_reset_list( ({
      MOB"malligator", MOB"turtle", MOB"mbat", MOB"fwaterbug", 
MOB"mcockroach", MOB"mdragonfly", MOB"fbat", MOB"fsnake", MOB"msnake", 
MOB"falligator", MOB"mwaterbug", MOB"mcockroach", MOB"mudbug"
  }) );
  set_properties( ([ "light" : 1,
                     "night light" : 0,
                     "swamp" : 1
                   ]) );
  set_short("Mystic Marsh.");
}
