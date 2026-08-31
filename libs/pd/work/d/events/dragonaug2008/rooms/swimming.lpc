
#include <std.h>
#include <dragonevent.h>

inherit ROOM;

int no_dismount(string);

void create() {
  ::create();
  set_properties( ([ "light" : 1, "night light" : 0, "no teleport" : 1,
    "no attack" : 1, "no magic" : 1, "no steal" : 1, "no bump" : 1,
    "water" : 1, "no map" : 1 ]) );
  set_short("in the water");
  set_day_long(
    "The ocean stretches out as far as the eye can see to the west. "
    "A towering rocky wall to the east begins to arch upwards and cover "
    "the area, creating a ceiling that keeps out much of the sunlight. "
    "Dazzling wave-born reflections play on every surface."
  );
  set_night_long(
    "Dark, ominous waters stretch out in most directions. A rock wall "
    "stands to the east and something solid is overhead, keeping out "
    "the moonlight. Everything is black."
  );
  set_items( ([
    "ocean" : "The vast ocean opens up to the west.",
    "wall" : "Solid rock, like the side of a mountain.",
    "ceiling" : "Solid rock, it hangs dangerously low overhead.",
    "reflections" : "Dim light bouncing off the waves and spraying "
      "white and blue patterns over the wall and ceiling.",
  ]) );
  set_listen("default", "The ocean waves break thunderously against the rocky wall.");
  set_touch("water", "The water is very cold to the touch.");
}

void init() {
  ::init();
  add_action("no_dismount", "dismount");
}

int no_dismount(string str) {
  message("info", "You cannot dismount right now!", this_player());
  return 1;
}
