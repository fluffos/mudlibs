#include <std.h>
#include "../fotia.h"

inherit ROOM;

void create() {
  ::create();
  set_name("a path");
  set_short("a ruined path");
  set_long("The air is thick with smoke making it hard to see. A large charred "
    "oak has fallen here, blocking the path.");
  set_smell(({"default", "wood", "burning wood"}), "The smell of burning "
    "wood lingers in the air.");
  set_listen(({"default", "wood", "burning wood"}), "The occasional crack "
    "and pop burning wood can be heard.");
  set_items(([
    ({"debris","path"}) : "The path is littered with the fragments of a once "
      "great forest.",
    ({"oak tree","tree","oak"}) : "A large oak tree is blocking the path."
  ]));
  set_exits(([
    "west"  : ROOMS "n_path_3"
  ]));
}

