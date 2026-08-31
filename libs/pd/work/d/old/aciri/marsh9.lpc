#include <aciri.h>
#include <std.h>
inherit PIER;

string *query_tracks();

void create() {
 ::create();
   set_short("%^BOLD%^%^BLACK%^Southwest of a large pond");
   set_day_long("%^BOLD%^%^BLACK%^"
     "A large pond that looks great for fishing is northeast of here. The dirt "
     "around the pond is very muddy and acts much like quicksand. Most directions "
     "are made impossible to walk by a thick growth of trees and northeast is "
     "blocked by a mid sized mass of murky water.");
   set_night_long("%^BOLD%^%^BLACK%^"
     "Crickets chirp interminably all night long. Light shines into this portion "
     "of the marsh from the large opening above a pond. The large pond looks like "
     "a great place to fish, from any angle. Fish dive into the air and splash "
     "back into the water.");
   set_items(([
     "pond" : "The pond is certainly big enough to fish in, but is too murky "
              "to see what would be caught.",
     "trees": "Trees grow in thick abundance to the south and west.",
     "mud"  : "Around the pond, the mud works much like quicksand.",
     "fish" : "They dive out of, then back into the water."
   ]));
   set_max_catch(20);
   set_chance(69);
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
      "northwest" : ROOMS"marsh10",
      "east"      : ROOMS"marsh8"
   ]));
}

string *query_tracks() { return ({ }); }
