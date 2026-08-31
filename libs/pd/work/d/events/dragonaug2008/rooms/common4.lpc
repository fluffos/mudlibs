
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
    "A huge chasm yawns open to the west, and a second small one to the "
    "east. Birds and insects fly past quite often, riding the drafts. "
    "The path here is atop a ridge which drops gently on either side, "
    "creating a dangerous place to linger."
  );
  set_items( ([
    "chasm" : "The chasm to the west is huge and extends very far "
      "north and south. The smaller one to the east can be seen across, "
      "but drops down quickly.",
    ({ "birds", "insects" }) : "They flit into and out of the chasms, "
      "finding food or becoming it.",
    "ridge" : "A rough rocky path between the chasms.",
  ]) );
  set_listen("default", "A light breeze whistles around the mountain.");
  set_exits( ([
    "north" : DRAG_ROOMS+"common1",
    "southeast" : DRAG_ROOMS+"common7",
  ]) );
}

void reset() {
  int i = random(2);
  object ob;
  ::reset();
  while (i > 0 && !(ob = present("dragon "+i))) {
    ob = new(DRAG_MOBS+"dragon");
    ob->move(this_object());
  }
}

