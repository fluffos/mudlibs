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
      "The desks are empty, so the class in this room must be dismissed.  Next to the writing "
      "board there are maps of far off places and instructions on how to write in the arcane "
      "forms.  The teacher's desk is empty.");
    set_exits( ([ "north" : ROOMS "mtower20",
                  "northwest" : ROOMS "mtower24",
                  "northeast" : ROOMS "mtower22" ]));
    set_smell("default", "Incence fills the air.");
    set_listen("default", "Crackling from an unseen fire.");
    set_items(([
        "desks" : "The desks are small, and probably designed to accomodate younger pupils.",
        "board" : "The board is blank, and must use a form of magic to be written on.",
        "maps" : "The maps are of places that seem not of this world.  They would be of no use to you.",
        "instructions" : "Looking at the instructions, you see how to write in arcane, but do not understand the language.",
        "desk" : "The teacher's desk is bare and unoccupied."
    ]));
}
