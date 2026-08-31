
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
    "The lake is very cold and very calm. It extends to the northwest with "
    "barely a ripple. A rock wall encloses the lake to the east, and the "
    "shore is to the south."
  );
  set_items( ([
    "lake" : "A cold, clear lake in the mountains.",
    "wall" : "The wall is sheer rock that goes straight up.",
    "shore" : "Slightly sandy dry ground.",
  ]) );
  set_exits( ([
    "south" : DRAG_ROOMS+"lakeside2",
    "southwest" : DRAG_ROOMS+"lakeside1",
    "west" : DRAG_ROOMS+"lake7",
    "northwest" : DRAG_ROOMS+"lake5",
  ]) );
}

void reset() {
  int i = random(2);
  object ob;
  ::reset();
  while (i > 0 && !(ob = present("blue dragon "+i))) {
    ob = new(DRAG_MOBS+"bluedragon");
    ob->move(this_object());
  }
}

