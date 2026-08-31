#include <aciri.h>
#include <std.h>
inherit ROOM;

string *query_tracks();

void create() {
 ::create();
   set_short("%^BOLD%^%^BLACK%^Near the edge of a dark marsh");
   set_day_long("%^BOLD%^%^BLACK%^"
     "The marsh is very dark humid. Vines climb the dark brown barked trees in "
     "twisted coils. Ferns and moss grow about the muddy ground. Tons of "
     "underbrush and tree saplings grow in the protein-full dirt. The rays of "
     "sunlight that come into the swamp shine into small puddles of water "
     "in the dips of the landscape.");
   set_night_long("%^BOLD%^%^BLACK%^"
     "The marsh is not only damp and humid but increadibly dark at night. Large "
     "trees have vines coiled about them and moss about them. Ferns and other "
     "underbrush grow in the muddy ground. Puddles of water rest in small dips "
     "in the marsh.");
   set_items(([
     "puddles" : "Puddles form in minature valleys in the marsh ground.",
     "dips"    : "The dips in the ground form minature valleys.",
     "ferns"   : "Ferns and moss grow in patches near the trees.",
     "saplings": "Tree saplings sprout in the muddy ground.",
     "vines"   : "Thick vines coil around the trees, in an upwards spiral."
   ]));
   set_properties((["light" : 2, "night light" : 2, "swamp" : 1 ]));
   set_exits(([
      "south" : ROOMS"marsh1",
      "north" : ROOMS"marsh3",
   ]));
}

string *query_tracks() { return ({ }); }
