
#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties( ([
    "light" : 2, "night light" : 1, "indoors" : 1, "mountain" : 1,
  ]) );
  set_short("a cave");
  set_long(
    "This is a large cave. The walls are completely smooth, and slope "
    "around to meet again in a flat ceiling. The deeper parts of the "
    "cave are southwest, but somehow it is easy to see here."
  );
  set_items( ([
    "cave" : "A smooth tunnel in the mountain.",
    "walls" : "They have been smoothed down so there are no rough parts.",
    "ceiling" : "The ceiling is far above and quite flat.",
  ]) );
  set_listen("default", "A breeze blows by just outside.");
  set_exits( ([
    "northeast" : DRAG_ROOMS+"bluepath4",
    "southwest" : DRAG_ROOMS+"bluepath2",
  ]) );
}

void reset() {
  int i = random(4);
  object ob;
  ::reset();
  while (i > 0 && !(ob = present("dragon "+i))) {
    ob = new(DRAG_MOBS+"dragon");
    ob->move(this_object());
  }
}

