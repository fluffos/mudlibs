#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
    ]));
    set_short("Mage Tower");
    set_long("An invisible barrier blocks the wind and cold weather from entering "
      "the bottom floor of the tower.  Pedestals with glowing spheres light up the "
      "room for all of the guests.  The rest of the room is plain, with a set of "
      "spiraling stairs leading further up the tower.");
    set_exits( ([ "out" : ROOMS "mtower00",
                  "up" : ROOMS "mtower10"
     ]));
    set_smell("default", "Incence fills the air.");
    set_listen("default", "Crackling from an unseen fire.");
    set_items(([
        "barrier" : "Unseen, it covers the open doorway from wind and cold, but allows people to pass through.",
        ({"pedestals", "spheres"}) : "The spheres glow cooly, filling the room with a soft light.",
        "stairs" : "The stairs lead up to the second story."
    ]));
}

void reset() {
    ::reset();
    if(!present("mage", this_object()))
      new(MOB"gmage")->move(this_object());
}
