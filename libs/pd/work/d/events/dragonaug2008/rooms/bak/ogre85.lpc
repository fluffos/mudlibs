#include <std.h>
#include <dragonevent.h>
inherit VAULT;
void create() {
    ::create();
    set_no_clean(1);
    set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
    set_short("Ogre Caves");
    set_long("%^BOLD%^%^BLACK%^The expected darkness of the caves is battled by small white crystals which escape from every crack and crevice.  A continuous dripping from a hole in the ceiling creates a %^BLUE%^puddle of water %^BLACK%^on the floor, %^WHITE%^glowing with light from the crystals%^BLACK%^.  Shadows twist and turn around every boulder, allowing their darkness to peek out around the cavern, only to be decimated by the %^WHITE%^crystals%^BLACK%^.  A delightful %^WHITE%^sparkle %^BLACK%^covers the ceiling, probably caused by the reflections in the %^BLUE%^puddle%^BLACK%^.%^RESET%^");

    set_smell("default", "%^RESET%^%^ORANGE%^The dank smell of the cave encompasses the room.%^RESET%^");
    set_listen("default", "Dripping water can be heard throughout the area.");
    set_exits( ([ "northwest" : DRAG_ROOMS "ogre74", "northeast" : DRAG_ROOMS "ogre75" ]) );
  foreach (string ex in query_exits())
    cover_exit_with_door(ex, DRAG_GEM_DOOR_ID);
  set_closed(DRAG_GEM_DOOR_ID, 0);
  set_door_name(DRAG_GEM_DOOR_ID, "magical barrier");
  set_door_func(DRAG_GEM_DOOR_ID, "enter",
    (: write("%^YELLOW%^The magical barrier stops you from leaving.%^RESET%^") :), "active");
}
void reset() {
  object ob;
  ::reset();
  if (!present("carved pillar")) {
    ob = new(DRAG_ITEMS+"pillar");
    ob->move(this_object());
    ob->set_color("white");
  }
}
