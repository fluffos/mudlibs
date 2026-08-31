#include <aciri.h>
#include <std.h>
inherit PIER;

string *query_tracks();

void create() {
 ::create();
   set_short("West of a large pond");
   set_day_long(""
     "A large pond lies directly east of this point in the marsh. The bank of "
     "the pond is very muddy and slopes into the water. The rest of the ground"
     "is a soft brown and black dirt. A few trees grow here, and those that do"
     "grow so thickly in certain parts allowing passage only southeast and "
     "north.");
   set_night_long(""
     "A large pond lies directly east of this point, but the dark night light "
     "stops any vision across the pond. ");
   set_items(([
     "
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
      "southeast" : ROOMS"marsh9",
      "north"     : ROOMS"marsh11"
   ]));
}

string *query_tracks() { return ({ }); }
