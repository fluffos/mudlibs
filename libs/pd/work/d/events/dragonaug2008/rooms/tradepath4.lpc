
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
    "services or special kills. A small chasm drops suddenly to the south, "
    "but the road is large enough for four dragons to walk abreast. "
    "Mountain peaks can be seen in the distance in all directions and "
    "smaller paths lead north and southward."
  );
  set_items( ([
    "road" : "As much a road as a path through a mountain can be.",
    "chasm" : "A very narrow but steep drop into nothingness.",
    "peaks" : "They rise up against the sky.",
  ]) );
  set_smell("default", "The smell of antiseptics fills the air.");
  set_exits( ([
    "north" : DRAG_ROOMS+"tradeconnect2",
    "east" : DRAG_ROOMS+"tradepath5",
    "southeast" : DRAG_ROOMS+"entrypath3",
    "west" : DRAG_ROOMS+"tradepath3",
  ]) );
}

void reset() {
  int i = random(3);
  object ob;
  ::reset();
  while (i > 0 && !(ob = present("dragon "+i))) {
    ob = new(DRAG_MOBS+"dragon");
    ob->move(this_object());
  }
  if (!present("dragon doctor"))
    new(DRAG_MOBS+"dragondoctor")->move(this_object());
}

