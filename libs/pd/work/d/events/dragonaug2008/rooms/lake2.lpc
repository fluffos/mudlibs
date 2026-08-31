
#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties( ([
    "light" : 2, "night light" : 0, "indoors" : 0, "mountain" : 1, "water" : 1,
  ]) );
  set_short("a lake");
  set_long(
    "A sheer cliff rises to the north. Water slips away in every other "
    "direction. The lake seems oddly empty; there are no fish or birds "
    "to be seen."
  );
  set_items( ([
    "cliff" : "The cliff to the north rises far above your head.",
    ({ "lake", "water" }) : "Clear and undisturbed water surrounds you and "
      "spreads to the south.",
  ]) );
  set_exits( ([
    "east" : DRAG_ROOMS+"lake3",
    "southeast" : DRAG_ROOMS+"bluelake",
    "west" : DRAG_ROOMS+"lake1",
  ]) );
}

void reset() {
  int i = random(3);
  object ob;
  ::reset();
  while (i > 0 && !(ob = present("blue dragon "+i))) {
    ob = new(DRAG_MOBS+"bluedragon");
    ob->move(this_object());
  }
}

