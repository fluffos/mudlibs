#include <std.h>

inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
    set_short("In a cottage");
    set_long(
      "This is apparently the kitchen of this small cottage. Cupboards "
      "line the walls directly above an old, worn counter top. An old "
      "looking cast iron stove sits in the center of the room, but is unlit. "
      "An open window appears is open, allowing for a breeze to come through. "
      "A doorway to the north leads outside. "
    );
    set_items(([
   "window" : "The window is open, making for a nice breeze filling the room. ",
   "stove" : "An old cast iron stove sits in the middle of the room. It isn't "
	     "lit but looks like it could heat the small cottage up nicely.",
   "cupboards" : "Cupboards line the walls. They rest above an old, worn counter top.",
   "counter" : "The counter top is worn from many years of use.",
   "kitchen" : "This appears to be the kitchen of the small cottage.",
    ]));
    set_exits( ([ 
        "north"  : "/d/nopk/forest/path/room/backyard",
        "south"  : "/d/nopk/forest/path/room/enter1"
    ]) );
}

