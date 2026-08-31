#include <std.h>
#include <dragonevent.h>

#define SAY(x) message("info", x, this_object())

inherit DRAG_ROOMS"py/logbase";

void create() {
  ::create();
  set_long("The inside of a hollow log. It is very cramped, the curved walls of the log press in from all directions. The log sways back and forth in the wind.");
  set_items( ([
    "log" : "you are standing inside of it.",
    ({"wall","walls"}) : "The walls of the log are made of wood.",
    "wood" : "Nothing special about it.",
  ]) );
  set_exits( ([
    "west" : DRAG_ROOMS"py/fall6",
    "east" : DRAG_ROOMS"py/fall7",
  ]) );
}

void heart_beat() {
  ::heart_beat();
  if(!player || !present(player)) return;

  if (query_print_status())
    print_status();
}
