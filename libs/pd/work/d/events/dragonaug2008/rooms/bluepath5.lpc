
#include <std.h>
#include <dragonevent.h>

inherit ROOM;

int show_msg();

void create() {
  ::create();
  set_properties( ([
    "light" : 2, "night light" : 0, "indoors" : 0, "mountain" : 1,
  ]) );
  set_short("a mountain");
  set_long(
    "The canyon walls still tower far above here, despite the height "
    "from being on top of the boulders. A couple bird nests can be "
    "seen clinging to the rocks above. More boulders connect to a "
    "solid path just to the south."
  );
  set_items( ([
    "canyon" : "Tall rocky walls with a path between them.",
    "nests" : "Clumps of ragged sticks and grasses, blown ragged by "
      "the winds.",
    "rocks" : "The whole area is made of rocks.",
    "boulders" : "Some huge pieces of rock that are underfoot.",
    "path" : "A large flat path through the canyon.",
  ]) );
  set_exits( ([
    "south" : DRAG_ROOMS+"bluepath4",
    "north" : DRAG_ROOMS+"lakepath2",
  ]) );
  add_pre_exit_function("north", "show_msg");
}

int show_msg() {
  object tp = this_player();
  if (tp && !tp->query_invis()) {
    message("info", tp->query_cap_name()+" clambers down some boulders.",
      environment(tp), tp);
    message("info", "You clamber down some boulders.", tp);
  }
  return 1;
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

