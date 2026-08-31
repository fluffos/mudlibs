#include <std.h>
#include <dragonevent.h>
inherit VAULT;
void create() {
    ::create();
    set_no_clean(1);
    set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
    set_short("Ogre Caves");
    set_long("%^BOLD%^%^WHITE%^Crystalline stalactites glitter %^BLACK%^dangerously overhead.  A faint concentration of %^YELLOW%^gold flickering dust %^BLACK%^can be seen fluttering from the cracks in the ceiling to the floor, %^YELLOW%^lighting up %^BLACK%^a tolerable path through the cave.  Thick %^WHITE%^crystallized pieces %^BLACK%^stick up from the floor at every angle.  One especially %^WHITE%^bright crystal %^BLACK%^seems almost to %^YELLOW%^glow%^BLACK%^.%^RESET%^");

    set_smell("default", "%^RESET%^%^ORANGE%^The dank smell of the cave encompasses the room.%^RESET%^");
    set_listen("default", "Dripping water can be heard throughout the area.");
    set_exits( ([ "southeast" : DRAG_ROOMS "ogre75", "southwest" : DRAG_ROOMS "ogre74" ]) );
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
    ob->set_color("blue");
  }
}
