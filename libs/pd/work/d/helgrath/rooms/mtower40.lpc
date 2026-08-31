#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
    ]));
    set_short("Mage Tower");
    set_long("The stairs stop just short of the large swirling ceiling.  Four mages stand "
      "at each corner of it, eyes closed and arms outstretched.  It seems that they are "
      "keeping the swirling thing going.  Otherwise, there is nothing else up here at the top "
      "of the tower.");
    set_exits( ([ "down" : ROOMS "mtower30" ]));
    set_smell("default", "Incence fills the air.");
    set_listen("default", "Crackling from an unseen fire.");
    set_items(([
        ({"stairway", "stairwell"}) : "The solid black stairs shine slightly in the light, but are not slick to the touch.",
        ({"object", "swirling object"}) : "It looks like some of the portals that you've seen mages create, except much bigger.",
        "mage" : "The mage ignores you completely, intent on the task at hand.",
        "passageway" : "The passageway leads off of the stairs onto the current floor."
    ]));
}
