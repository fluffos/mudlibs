
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
    "The path here is narrower than most, squeezed between mountain peaks "
    "to the east and a large chasm to the west. The ground slopes slightly "
    "toward the chasm, and loose pebbles roll down into it. Some birds "
    "circle warily overhead."
  );
  set_items( ([
    "peaks" : "The peaks rise up against the sky.",
    "chasm" : "It is dizzyingly deep and far too close.",
    "pebbles" : "They slide down into the chasm and bounce a few times "
      "before being swallowed by darkness.",
    "ground" : "It is sloped a bit, rising towards the peaks and falling "
      "towards the chasm. This seems like a dangerous place to spend time.",
    "birds" : "They are mere specks in the sky.",
  ]) );
  set_listen("default", "A heavy wind blows through, dislodging bits of rock.");
  set_exits( ([
    "north" : DRAG_ROOMS+"tradeconnect1",
    "southeast" : DRAG_ROOMS+"tradepath5",
    "south" : DRAG_ROOMS+"tradepath4",
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

