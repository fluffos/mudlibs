#include <aciri.h>
#include <std.h>
inherit ROOM;

string *query_tracks();

void create() {
 ::create();
   set_short("%^BOLD%^%^BLACK%^Nearing the center of the marsh");
   set_day_long("%^BOLD%^%^BLACK%^"
     "Possibly the center of the marsh, but not quite as dark as would be "
     "expected, this part of the marsh has more lizards and other small creatures "
     "running around than trees growing. Saplings grow here, and a few fallen "
     "trees lay in the mud. Birds can be heard chirping all day long.");
   set_night_long("%^BOLD%^%^BLACK%^"
     "Crickets and grasshoppers can be heard all night long, along with the "
     "croaking of frogs. Lizards and snakes roam about during the night hours. "
     "A small ammount of moonlight actually gets to this part of the murk.");
   set_items(([
     "lizards" : "Lizards and other smaller animals and reptiles scramble about.",
     "frogs"   : "Frogs hop through the mud and water.",
     "marsh"   : "Not quite the center of the marsh, but very near.",
     "saplings": "Saplings grow in the soft dirt.",
     "trees"   : "Several trees have fallen and lie in the mud."
   ]));
   set_properties((["light" : 2, "night light" : 1, "swamp" : 1 ]));
   set_exits(([
      "south" : ROOMS"marsh6",
      "north" : ROOMS"marsh8",
   ]));
}

string *query_tracks() { return ({ }); }
