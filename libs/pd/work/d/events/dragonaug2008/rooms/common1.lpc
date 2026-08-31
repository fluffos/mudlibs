
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
    "Several paths converge here and lead around many mountain obstacles. "
    "A mesa stands tall to the north, and paths lead around both sides of it. "
    "The path south is flanked by deep chasms, and seems rather dangerous. "
    "This area is wide open and has been cleared of most loose rock to "
    "create a gathering spot."
  );
  set_items( ([
    "paths" : "Many paths through the mountains, some atop ridges and "
      "some between high walls.",
    "mesa" : "A tall flat hunk of rock with a group of trees huddled together "
      "on the top.",
    "trees" : "They grow very close together, taking up all the "
      "room on the mesa.",
    "chasms" : "A huge chasm opens to the west, and a much smaller one "
      "to the southeast. They drop quickly into darkness.",
  ]) );
  set_listen("default", "A light breeze whistles around the mountain.");
  set_exits( ([
    "northwest" : DRAG_ROOMS+"chasmside",
    "northeast" : DRAG_ROOMS+"whitecaveoutside",
    "east" : DRAG_ROOMS+"common2",
    "south" : DRAG_ROOMS+"common4",
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

