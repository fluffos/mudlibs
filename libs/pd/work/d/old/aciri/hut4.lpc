#include <aciri.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("In the shambles of a hut");
   set_day_long(
     "This grass hut is in shambles. Sticks jut upwards, into the empty space "
     "where the ceiling would have been. It is possible that the ceiling was "
     "blown off during a great storm. Sticks, grass, and leaves litter the "
     "ground.");
   set_night_long(
     "The entire roof of the hut is missing. Sticks and other materials have "
     "fallen to the ground. The black night time sky can be seen from this hut, "
     "thanks to the missing roof. The door has been ripped out of the doorway, "
     "and lies in the center of the room.");
   set_items(([
     ({ "sticks", "grass", "leaves" }) : "Leaves, grass and sticks litter the "
                  "ground in a jangled mess.",
     "ceiling" : "For some reason, there is no ceiling on this hut.",
     "roof" : "At one point in time, the root was removed from the hut, but "
              "how and why?",
     "door" : "There is no phsyical damage to the door, other than being taken "
              "out of the doorway."
   ]));
   set_properties((["light" : 3, "night light" : 2 ]));
   set_exits(([
      "south" : ROOMS"beach7"
   ]));
}

// string *query_tracks() { return ({ }); }
