
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
    "The large chasm to the west looms dangerously close, but a stone "
    "walkway has been erected which leads over it and out to a plateau. "
    "The walkway is curved, resembling an inversed archway. It seems "
    "to be secured rather well to the mountainside. Northwards, the path "
    "opens up a bit into a wider space. Mountain peaks rise high above in "
    "all directions, but the plateau is higher than any of them."
  );
  set_items( ([
    "chasm" : "A wide, deep drop into nothingness.",
   ({ "walkway", "archway" }) : "This stone marvel leads steeply up towards "
     "the top of the plateau.",
   "peaks" : "They rise up against the sky.",
   "plateau" : "It is the highest point visible. The walkway rises quickly "
     "up towards the top of it, which can't be seen from here.",
  ]) );
  set_exits( ([
    "north" : DRAG_ROOMS+"common7",
    "west" : DRAG_ROOMS+"dragnorth42",
    "south" : DRAG_ROOMS+"tradeconnect2",
  ]) );
}

void reset() {
  int i = random(3);
  object ob;
  ::reset();
  while (i > 0 && !(ob = present("red dragon "+i))) {
    ob = new(DRAG_MOBS+"reddragon");
    ob->move(this_object());
  }
}

