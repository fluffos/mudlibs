#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    object ob;
    ::create();
    set_properties(([
      "light" : 2,
    ]));
    set_short("Mage Tower");
    set_long("This is the mage's meditation chambers.  Mages retreat here to relax and not be "
      "distrubed while they ponder visions and spells they have created.  Many mages sit on "
      "uncomfortable looking mats, eyes closed in repose.  It'd best be wise not to disturb "
      "any of them.");
    set_exits( ([ "north" : ROOMS "mtower30",
                  "northwest" : ROOMS "mtower34",
                  "northeast" : ROOMS "mtower32" ]));
    set_smell("default", "Incence fills the air.");
    set_listen("default", "A needle could be heard if it were dropped on a pillow.");
    set_items(([
        "desks" : "The desks are small, and probably designed to accomodate younger pupils.",
        "board" : "The board is blank, and must use a form of magic to be written on.",
        "maps" : "The maps are of places that seem not of this world.  They would be of no use to you.",
        "instructions" : "Looking at the instructions, you see how to write in arcane, but do not understand the language.",
        "desk" : "The teacher's desk is bare and unoccupied."
    ]));
    //Because nightshade is cheap and lazy.
    ob = new(MOB"tmage");
    ob->set_short("Three Powerful Mages");
    ob->move(this_object());
}
