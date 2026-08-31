
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
    "The Great Southern Ridge\n"
    "This flat road is often filled with dragons, bartering their "
    "services or special kills. Tall mountain peaks rise directly "
    "to the east, casting shadows on the area. The larger surrounding "
    "area creates a small plateau here."
  );
  set_items( ([
    "road" : "As much a road as a path through a mountain can be.",
    "peaks" : "They rise up against the sky.",
    "shadows" : "Long pointed shadows that move with the sun and moon.",
    "plateau" : "This is a rocky plateau with a wide open area for "
      "dragons to spend time.",
  ]) );
  set_listen("default", "A light breeze whistles around the mountain.");
  set_exits( ([
    "southeast" : DRAG_ROOMS+"entrypath4",
    "south" : DRAG_ROOMS+"entrypath3",
    "west" : DRAG_ROOMS+"tradepath4",
    "northwest" : DRAG_ROOMS+"tradeconnect2",
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

