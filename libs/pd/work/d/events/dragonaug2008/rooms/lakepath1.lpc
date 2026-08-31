
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
    "The road here leads away from the large common area and towards a "
    "canyon to the east. There are high walls on either side of the path. "
    "Some bones and food scraps lie around."
  );
  set_items( ([
    ({ "road", "path" }) : "The road leads west to the common area, "
      "and east to a canyon.",
    "canyon" : "A path between towering rock walls.",
    "walls" : "Steep rock.",
    ({ "bones", "scraps" }) : "They look to be fish bones and some scales.",
  ]) );
  set_exits( ([
    "east" : DRAG_ROOMS+"lakepath2",
    "west" : DRAG_ROOMS+"commonrocky4",
  ]) );
}

void reset() {
  int i = random(3);
  object ob;
  ::reset();
  while (i > 0 && !(ob = present("dragon "+i))) {
    ob = new(DRAG_MOBS+"dragon");
    if (random(3)) {
      ob->set_moving(1);
      ob->set_speed(18);
    }
    ob->move(this_object());
  }
}

