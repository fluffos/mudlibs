#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_properties( ([ "light" : 2, "indoors" : 1 ]) );
    set_short("a plain shack");
    set_long(
      "Floorboards and walls made of long rotting wood are the "
      "only features of an otherwise barren shack.  The only "
      "entrance is an opening to the south where a door once "
      "used to be.  Time and the environment must have taken "
      "it away."
    );
    set_smell("default", "Mildew fills your lungs, nearly making you sick.");
    set_listen("default", "The floorboards creak under you as you walk.");
    set_smell("mildew", "That really makes you sick!");
    set_listen(({ "floorboards", "floorboard" }),
      "Old and unhappy with your presence, they are crying out.");
    set_items( ([
      ({ "floorboard", "floorboards" }) : 
        "Be careful where you walk, they are rotting through in places.",
      ({ "entrance", "opening" }) :
        "A doorway with no door that leads out into the woods.",
      "woods" : "The great woods which surround the shack.",
      "door" : "What door?", "shack" : "An old, abandoned shack." ]) );
    set_exits( ([ "south" : "/domains/Examples/room/search" ]) );
}
