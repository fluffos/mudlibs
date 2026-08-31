
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
    "The path enters a canyon here. It turns sharply north, with a "
    "rock wall rising to the east. Some boulders are strewn around "
    "near the sheer walls. A road leads west, back towards a larger "
    "open area."
    " The boulders pile up against the wall to the south."
  );
  set_items( ([
    "canyon" : "Tall rocky walls with a path between them.",
    "wall" : "The wall is sheer rock.",
    "boulders" : "Mostly rounded, but the tops look curiously flat.",
    "road" : "It leads back to the main common area.",
  ]) );
  set_search( ({ "default", "boulders" }),
    "There seems to be a path to the south, just atop the boulders.");
  set_exits( ([
    "north" : DRAG_ROOMS+"lakepath3",
    "south" : DRAG_ROOMS+"bluepath5",
    "west" : DRAG_ROOMS+"lakepath1",
  ]) );
  add_invis_exit("south");
  add_pre_exit_function("south", "show_msg");
}

int show_msg() {
  object tp = this_player();
  if (tp && !tp->query_invis()) {
    message("info", tp->query_cap_name()+" clambers up some boulders.",
      environment(tp), tp);
    message("info", "You clamber up some boulders.", tp);
  }
  return 1;
}

