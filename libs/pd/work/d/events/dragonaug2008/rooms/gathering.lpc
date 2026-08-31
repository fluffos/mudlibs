
#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties( ([
    "light" : 2, "night light" : 1, "indoors" : 0, "mountain" : 1,
  ]) );
  set_short("a cave opening");
  set_long(
    "This large cavern is obviously a gathering place for the dragons. "
    "Large, arched tunnels lead off in several directions. Framing "
    "each tunnel is a pair of large torches carved into the cave walls; "
    "their flames are magically bright white and illuminate everything. "
    "To the south, the cave opens up to the sky."
  );
  set_items( ([
    "cavern" : "An open area inside the mountain.",
    "tunnels" : "Large and magnificent, their arches and carvings "
      "seem to be made to present elder dragons as they enter.",
    "torches" : "Each torch carving is about ten feet tall. "
      "The magical white flames barely leave the wall.",
    "walls" : "They are beautiful rock walls, filled with sparkling "
      "minerals and stripes of color.",
  ]) );
  set_touch( ({ "flames", "flame", "torches", "torch" }),
    "The magical torch flames are cool to the touch.");
  set_exits( ([
    "north" : DRAG_ROOMS+"entryred",
    "northeast" : DRAG_ROOMS+"entrywhite",
    "east" : DRAG_ROOMS+"entryblue",
    "south" : DRAG_ROOMS+"summit",
    "northwest" : DRAG_ROOMS+"entryblack",
  ]) );
}

void reset() {
  string *c = ({ "white", "blue", "black", "red" });
  ::reset();
  foreach (string col in c) {
    object ob;
    if (!present(col+" dragon")) {
      ob = new(DRAG_MOBS+col+"dragon");
      ob->move(this_object());
    }
  }
}

