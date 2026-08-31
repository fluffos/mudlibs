#include <std.h>
#include "../fotia.h"

inherit ROOM;

void create() {
  ::create();
  set_name("a path");
  set_short("a ruined path");
  set_long("Small plumes of smoke continue to rise from the ashes of a "
    "once great forest. The path is covered in small, black pieces of wood "
    "making travel difficult. Several large plumes of smoke can be seen in "
    "the distance.");
  set_smell(({"default", "wood", "burning wood"}), "The smell of burning "
    "wood lingers in the air.");
  set_listen(({"default", "wood", "burning wood"}), "The occasional crack "
    "and pop burning wood can be heard.");
  set_exits(([
    "north" : ROOMS "entrance",
    "south" : ROOMS "n_path_3"
  ]));
}

