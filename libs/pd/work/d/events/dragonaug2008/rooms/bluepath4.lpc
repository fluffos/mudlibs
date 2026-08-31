
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
    "The high path here begins to lead into a cave. Canyon walls tower above "
    "on both sides. The large cave opening to the southwest is a little dark, "
    "but the path seems well traveled."
  );
  set_items( ([
    "path" : "A space between the canyon walls.",
    "canyon" : "High rocky walls with a space between them.",
    "cave" : "A slightly dark cave mouth. It is really big.",
  ]) );
  set_listen("default", "A light breeze whistles around the mountain.");
  set_exits( ([
    "north" : DRAG_ROOMS+"bluepath5",
    "southwest" : DRAG_ROOMS+"bluepath3",
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

