#include <std.h>
#include <dragonevent.h>
inherit VAULT;
void create() {
    ::create();
    set_no_clean(1);
    set_properties( (["indoors": 1, "light": 2, "mountain": 1, "no teleport": 1 ]) );
    set_short("Ogre Caves");
    set_long("%^BOLD%^%^BLACK%^It appears as if many cave-ins have happened in this part of the cave.  Piles of rocks litter the ground, as if placed there for a reason.  At least two feet of rock covers all exits, as if they were completely covered, but the rocks moved.  Shadows dance behind the piles of rocks, swaying in a romantically deceptive motion.  There is a circle of rocks surrounding charred wood in the center of the room as if a fire pit had been here some time ago.%^RESET%^");

    set_smell("default", "%^RESET%^%^ORANGE%^The dank smell of the cave encompasses the room.%^RESET%^");
    set_listen("default", "Dripping water can be heard throughout the area.");
    set_exits( ([ "southeast" : DRAG_ROOMS "ogre85", "northeast" : DRAG_ROOMS "ogre63" ]) );
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
    ob->set_color("black");
  }
}
