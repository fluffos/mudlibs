#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
    ]));
    set_short("Mage Tower");
    set_long("Desks are all arranged in rows, with a writing board at the front of the room.  "
      "Students sit attentively as their teacher instructs them in the arcane arts.  Each student "
      "carefully waves their wand, trying to create a bag.  Some students sit with flat pieces of "
      "cloth, and others with 'bags' with no openings.  It seems that they still need a little practice.");
    set_exits( ([ "northwest" : ROOMS "mtower23",
                  "southwest" : ROOMS "mtower21" ]));
    set_smell("default", "Incence fills the air.");
    set_listen("default", "Crackling from an unseen fire.");
    set_items((["desks" : "The desks are small, and probably designed for younger pupils.",
        "bags" : "The students' lack of skill has created bags of all shapes and sizes."
    ]));
}

void reset() {
    ::reset();
    if(!present("teacher", this_object()))
      new(MOB"tmage")->move(this_object());
    if(!present("studying mage", this_object())) {
      new(MOB"smage")->move(this_object());
      new(MOB"smage")->move(this_object());
      if(random(4) == 0)
        new(MOB"smage")->move(this_object());
    }
}
