#include <std.h>
#include <sabserver.h>
inherit DESERT;
#include <std.h>
#include <sabserver.h>
inherit VIRTUALSERVER;
void create() {
  ::create();
  set_how_long(4);
  set_day_sentances( ({
   "An oasis appears off in the distance.",
   "The sand underfoot shifts and changes with the trek across the dunes.",
   "A snake in the distance makes it's way up a sand dune.",
   "A nearby cactus is turning brown from lack of water.",
   "The waves of heat rolling off the desert make things in the distance shimmer and change.",
   "The heat is repressive causing all but the most stubborn of animals the seek shelter.",
   "A wavering snake trail heads up and over a small sand dune.",
   "The hazy vision of an heavenly oasis fades into the desert heat.",
   "A sudden sandstorm blows through forever changing the sand dunes.",
   "Scattered cactuses provide little shade from the searing heat.",
   "The sun hangs high in the cloudless sky.",
   "Lizards scurry across the hot sand in search of shade.",
   "After hiking that last sand dune another one appears ahead.",
   "A light breeze fills the footprints that were left behind in the sand.",
   "Some scrubs litter the desert floor no higher than a foot in height.",
   "For as far as the eye can see nothing but a sea of sand dunes, cactuses, and scrubs.",
   "Shifting winds push a sand dune to a new location.",
   "A herd of camels quickly crosses the sand.",
   "The dunes across the sandy desert are buffeted by the unyielding presence of the piercing sun.",
   "The sand lays waiting for the most subtle breeze to change its complection forever.",
  }) );

  set_night_sentances( ({
   "A light desert breeze cools the hot sand.",
   "The sand takes on an unreal quality in the darkness and nearly glows under the moonlight.",
   "Lots of creatures roam about the desert at night foraging for food.",
   "Some of the catcuses have bloomed in the darkness of night.",
   "Animal calls off in the distance attest to the fact that the desert is teaming with life at night.",
   "Steam rises from a nearby cactus.",
   "The desert is alive with creatures at night.",
   "The coolness of the night is a drastic change from the heat of the day.",
   "The flowering cactuses make the desert lush at night.",
   "Shadows dances across the desert.",
   "Greeted by a night of crystal purity, filled with the stars glistening across the sky.",
   "A couple of lizards playfully roll around in the sand.",
   "The desert wind whips sand into small cyclones that dance and twirl over the dunes.",
   "During the tranquil twilight, the barroness of the desert gives way to a nobility of scenic wonder.",
   "The stars hover in a chaos above, yet there still remains an order that can never be explained.",
   "Over a dune, towers a magnificent structure that stands in complete ignorace of the desert winds.",
  }) ); 

  set_item_list( ([
        "sand" : "Thousands upon thousands of grains of white sand.",
        "scrubs" : "Small spindly plants.",
        "cactus"   : "A hardy desert plant covered in spines.",
        "cactuses" : "Many different kinds of Cactus thrive in the desert",
        "trail"   : "The trail left behind by a snake",
        "dunes"   : "Mounds of sand creating a hill and valley system across the desert.",
        "dune" : "A large pile of sand",
        "oasis" : "A small pool of water surrounded by trees and plants...ahh! It faded from sight!",
        "lizards"  : "Small reptiles that live in this desert.",
        "sun" : "A great ball of heat hanging in the sky.",
        "camels"  : "A four legged creature that lives in this desert.",
        "snake"   : "One of the small reptiles that thrive in the desert.",
        "shadows" : "The shadow of something.",

  ]) );

    set_smell("The searing heat dulls the sense of smell.");
    set_listen("The wind wistles off in the distance.");

  set_reset_list( ({
      MOB"camillion", MOB"cactus", MOB"desertsnake", MOB"fireant", MOB"sandirk", MOB"wolfspider"
  }) );
  set_properties( ([ "light" : 2,
                     "night light" : 1,
                     "desert" : 1
                   ]) );
  set_short("A desert.");
}
