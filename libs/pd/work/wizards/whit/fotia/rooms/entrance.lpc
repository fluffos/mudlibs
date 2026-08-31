#include <std.h>
#include "../fotia.h"

inherit ROOM;

void create() {
  ::create();
  set_name("a path");
  set_short("a ruined path");
  set_long("To the south a once mighty forest can be seen. It looks as if a "
      "wildfire recently ravaged the forest leaving only burnt stumps "
      "where once tall trees stood. Multple smoke plumes can be seen "
      "rising into the sky.");
  set_smell(({"default", "wood", "burning wood"}), "The smell of burning "
      "wood lingers in the air.");
  set_listen(({"default", "wood", "burning wood"}), "The occasional crack "
      "and pop burning wood can be heard.");
  set_exits(([
      "south" : ROOMS "n_path_1"
  ]));
}

