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
      "carefully waves their wand, trying to create water.  The students have glasses sitting in front "
      "of them that they are trying to fill.  Some glasses are filled with sludge, while others are filled "
      "with acid.  Only a few have managed to create water, and even those have created a few gallons too much.");
    set_exits( ([ "southeast" : ROOMS "mtower22",
                  "southwest" : ROOMS "mtower24" ]));
    set_smell("default", "Incence fills the air.");
    set_listen("default", "Crackling from an unseen fire.");
    set_items((["desks" : "The desks are small, and probably designed for younger pupils.",
        "glasses" : "Small glasses resting on the student's desks.  They're filled with various fluids."
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
