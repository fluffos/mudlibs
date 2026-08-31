#include <std.h>
#include <dragonevent.h>
inherit ROOM;
void create() {
    ::create();
    set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
    set_short("Ogre Caves");
    set_long("%^BOLD%^%^BLACK%^The expected darkness of the caves is battled by small white crystals which escape from every crack and crevice.  A continuous dripping from a hole in the ceiling creates a %^BLUE%^puddle of water %^BLACK%^on the floor, %^WHITE%^glowing with light from the crystals%^BLACK%^.  Shadows twist and turn around every boulder, allowing their darkness to peek out around the cavern, only to be decimated by the %^WHITE%^crystals%^BLACK%^.  A delightful %^WHITE%^sparkle %^BLACK%^covers the ceiling, probably caused by the reflections in the %^BLUE%^puddle%^BLACK%^.%^RESET%^");

    set_smell("default", "%^RESET%^%^ORANGE%^The dank smell of the cave encompasses the room.%^RESET%^");
    set_listen("default", "Dripping water can be heard throughout the area.");
    set_exits( ([ "southwest" : DRAG_ROOMS "ogre120" ]) );
}
void reset() {
    ::reset();

  if(!present("light column")) {
    object col = new(DRAG_ITEMS"lightcolumn");
    if(col) col->set_number(5);
    if(col) col->move(this_object());
  }
}
