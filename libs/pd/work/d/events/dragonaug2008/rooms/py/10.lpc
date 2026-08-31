#include <std.h>
#include <dragonevent.h>

inherit DRAG_ROOMS+"py/base";

void create() {
  ::create();
  set_long("%^BOLD%^%^BLACK%^A dark cave... It is nearly impossible to see in any direction. The entire eastern wall has dissolved into a tremendous jagged hole. The floor is soaked in a deep red %^RESET%^%^RED%^blood%^BOLD%^%^BLACK%^.");
  add_item("blood", "%^RED%^The floor is soaked in it.");
  set_exits( ([
    "east" : DRAG_ROOMS"py/final",
  ]) );
}
