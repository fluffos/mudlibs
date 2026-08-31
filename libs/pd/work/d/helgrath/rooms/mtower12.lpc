#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
    ]));
    set_short("Mage Tower");
    set_long("Books, books books.  They seem to fill the room entirely.  Some lay open upon the "
      "benches that cover any space not piled high with books.  It would take many lifetimes to "
      "read all of these.  Some small reading lights cast shadows across the floor.  An artifact "
      "or two rest next to a stack of books about ancient craftsmanship.");
    set_exits( ([ "northwest" : ROOMS "mtower13",
                  "southwest" : ROOMS "mtower11" ]));
    set_smell("default", "Incence fills the air.");
    set_listen("default", "Crackling from an unseen fire.");
    set_items(([
        "books" : "Books of every type that can be imagined are stacked and sorted into different piles.",
        "stairwell" : "The stairs spiral up the middle of the tower, while the rooms wrap around the outside.",
        "benches" : "The benches must have been made by the mages, and without magic.  Its surprising they can hold any weight.",
        "artifacts" : "They seem like old pieces of junk, but are probably powerful magic items.",
        "shadows" : "They're dark areas on the ground.  Nothing too exciting."
    ]));
}

void reset() {
    ::reset();
    if(!present("mage", this_object())) {
      new(MOB"lmage")->move(this_object());
      if(random(8) == 0)
        new(MOB"lmage")->move(this_object());
    }
}
