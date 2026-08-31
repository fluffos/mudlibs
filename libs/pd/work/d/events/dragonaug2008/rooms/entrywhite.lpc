
#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties( ([
    "light" : 2, "night light" : 0, "indoors" : 1, "mountain" : 1,
  ]) );
  set_short("a tunnel");
  set_long(
    "This is a wide tunnel through the mountain. Torches are all over the "
    "walls, providing light. The rocky walls have occaisonal white crystals "
    "in them which twinkle brightly. The floor is smooth, but the rest of "
    "the tunnel is rough rock and crystal."
  );
  set_items( ([
    "tunnel" : "This tunnel leads from the open areas north to a "
      "large cave southwest.",
    "torches" : "Mostly oil torches, placed into holes bored into the walls.",
    "walls" : "They have white crystals running through them which twinkle "
      "in the torch light.",
    "floor" : "The floor has been smoothed down for easy travel.",
    "crystals" : "Whitish quartz and other minerals.",
  ]) );
  set_exits( ([
    "north" : DRAG_ROOMS+"entrypath3",
    "northeast" : DRAG_ROOMS+"entrypath4",
    "southwest" : DRAG_ROOMS+"gathering",
  ]) );
}

void reset() {
  int i = random(2);
  object ob;
  ::reset();
  while (i > 0 && !(ob = present("white dragon "+i))) {
    ob = new(DRAG_MOBS+"whitedragon");
    ob->move(this_object());
  }
}

