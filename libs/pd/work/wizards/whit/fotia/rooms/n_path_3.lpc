#include <std.h>
#include "../fotia.h"

inherit ROOM;

void create() {
  ::create();
  set_name("a path");
  set_short("a ruined path");
  set_long("The path splits here, going both east and west. The air is thick "
    "with smoke making it hard to see. The path is littered with debris "
    "making travel on it difficult.");
  set_smell(({"default", "wood", "burning wood"}), "The smell of burning "
    "wood lingers in the air.");
  set_listen(({"default", "wood", "burning wood"}), "The occasional crack "
    "and pop burning wood can be heard.");
  set_items(([
    ({"debris","path"}) : "The path is littered with the fragments of a once "
      "great forest."
  ]));
  set_exits(([
    "north" : ROOMS "n_path_1",
    "east"  : ROOMS "n_path_4",
    "west"  : ROOMS "n_path_2"
  ]));
}

