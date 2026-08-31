#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
    ]));
    set_short("Mage Tower");
    set_long("The walls seem made up entirely of books.  This is definately the library of "
      "the tower.  A few crude benches are scattered throughout the room.  The room seems to "
      "wrap around the stairwell in the middle of the tower.  A few artifacts are resting on "
      "some of the benches.");
    set_exits( ([ "north" : ROOMS "mtower10",
                  "northwest" : ROOMS "mtower14",
                  "northeast" : ROOMS "mtower12" ]));
    set_smell("default", "Incence fills the air.");
    set_listen("default", "Crackling from an unseen fire.");
    set_items(([
        "books" : "Books of every type that can be imagined are stacked and sorted into different piles.",
        "stairwell" : "The stairs spiral up the middle of the tower, while the rooms wrap around the outside.",
        "benches" : "The benches must have been made by the mages, and without magic.  Its surprising they can hold any weight.",
        "artifacts" : "They seem like old pieces of junk, but are probably powerful magic items."
    ]));
}

void reset() {
    ::reset();
    if(!present("mage", this_object())) {
      new(MOB"lmage")->move(this_object());
      if(random(5) == 0)
        new(MOB"lmage")->move(this_object());
    }
}
