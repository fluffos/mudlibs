#include <aciri.h>
#include <std.h>
inherit PIER;

string *query_tracks();

void create() {
 ::create();
   set_short("%^BOLD%^%^BLACK%^In a gloomy marsh");
   set_day_long("%^BOLD%^%^BLACK%^"
     "The constant greys and browns of the marsh begins to get depressing. Even "
     "the large pond to the north is a muddy brown color. Further passage north "
     "is prevented by a large pond with fish and frogs hopping into the water. "
     "The pond is just big enough for fishing from any angle.");
   set_night_long("%^BOLD%^%^BLACK%^"
     "Crickets along with croaking frogs fill the night air. The dark tones of "
     "swamp have become an ominous presence, and a depressing one at that. Fallen "
     "branches have halfway sunk into the muddy ground. A large pond to the north "
     "is great for fishing in from any angle it is approached.");
   set_items(([
     "pond"  : "This pond would be great for fishing in.",
     "mud"   : "Branches are halfway sunken into it. The mud is firm enough to "
               "provide real support here.",
     "ground": "The ground is more like dirt here than mud.",
     ({ "fish", "frogs" }) : "Fish and frogs jump happily in the pond."
   ]));
   set_max_catch(20);
   set_chance(90);
   set_max_fishing(2);
   set_fish(([
     "crayfish"         : 5,
     "baby aligator"    : 12,
     "large mouth bass" : 9,
     "small mouth bass" : 7,
     "carp"             : 6,
     "frog"             : 6
   ]));
   set_properties((["light" : 2, "night light" : 1, "swamp" : 1 ]));
   set_exits(([
      "south" : ROOMS"marsh7",
      "west"  : ROOMS"marsh9",
      "east"  : ROOMS"marsh19"
   ]));
}

string *query_tracks() { return ({ }); }
