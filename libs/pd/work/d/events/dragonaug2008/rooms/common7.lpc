
#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties( ([
    "light" : 2, "night light" : 0, "indoors" : 0, "mountain" : 1,
  ]) );
  set_short("a mountain");
  set_long(
    "A stone walkway has been erected here. It leads over a chasm to the "
    "west and up to a plateau. The walkway is curved, resembling an inversed "
    "archway. It seems to be secured rather well to the mountainside. "
    "Another, smaller chasm drops swiftly to the north. The ground curves "
    "gently around the dropoffs and the low peaks to the east, creating "
    "an inviting and sheltered area here."
  );
  set_items( ([
    ({ "walkway", "archway" }) : "This stone marvel leads steeply up towards "
      "the top of the plateau.",
    "chasm" : "There is a large one on the western side and a smaller one "
      "just to the north. Both drop quickly into darkness",
    "peaks" : "They rise up against the sky.",
    "plateau" : "It is the highest point visible. The walkway rises quickly "
      "up towards the top of it, which can't be seen from here.",
  ]) );
  set_exits( ([
    "northeast" : DRAG_ROOMS+"common5",
    "east" : DRAG_ROOMS+"common8",
    "south" : DRAG_ROOMS+"tradeconnect1",
    "northwest" : DRAG_ROOMS+"common4",
    "southwest" : DRAG_ROOMS+"dragnorth42",
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

