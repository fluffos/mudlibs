
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
    "The mountain rises in a tall spire to the east, which drops down into "
    "a chasm on its north face. The open area here is a place where "
    "dragons often spend time. A bright tunnel leads through the mountain "
    "to the southwest."
  );
  set_items( ([
    "mountain" : "A huge mass of rock pushed upwards over the centuries.",
    "spire" : "A sharp jut of rock that stands against the sky.",
    "chasm" : "A deep drop into nothing.",
    "tunnel" : "The tunnel seems to twinkle.",
  ]) );
  set_listen("default", "A light breeze whistles around the mountain.");
  set_exits( ([
    "southwest" : DRAG_ROOMS+"entrywhite",
    "west" : DRAG_ROOMS+"entrypath3",
    "northwest" : DRAG_ROOMS+"tradepath5",
  ]) );
}

void reset() {
  int i = 1+random(3);
  object ob;
  ::reset();
  while (i > 0 && !(ob = present("dragon "+i))) {
    ob = new(DRAG_MOBS+"dragon");
    ob->move(this_object());
  }
}

