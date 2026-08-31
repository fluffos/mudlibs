
#include <std.h>
#include <saahr.h>

inherit HOUSE_ROOM;

void wade_msg();

void create() {
  ::create();
  set_properties(([
    "light":2,
    "night light":1,
    "indoors":0,
    "town":1
  ]));
  set_short("a small town");
  set_long(
    "Trees and bushes line the path. Most of the town lies to the east. "
    "A house sits at the end of the path, with a few flowering bushes "
    "planted out front. Behind the house down a bank, a river flows quietly."
  );
  set_items(([
    "trees" : "Tall, thick trees full of leaves.",
    "bushes" : "The bushes along the path have been cut into a pleasing "
      "oval shape, while the ones in front of the house have grown naturally "
      "and have several white and yellow flowers growing from them.",
    "flowers" : "Round white and yellow flowers.",
    "path" : "A packed dirt path that leads towards the house to the west "
      "and into town to the east.",
    "town" : "Several wooden buildings with paths between them.",
    "river" : "The river looks kind of shallow, it might be possible to wade through.",
  ]));
  set_listen("default", "Water flowing.");
  set_exits(([
    "enter house":VPROOMS"house9_8",
    "northeast":VPROOMS"town10_7",
    "east":VPROOMS"town10_8",
    "southeast":VPROOMS"town10_9",
    "wade":VPROOMS"river8h_8",
  ]));
  add_invis_exit("wade");
  add_post_exit_function("wade", "wade_msg" );
  check_door();
}

void wade_msg() {
  message("info",
    "%^BOLD%^%^BLUE%^As you wade into the river, "
    "you slip on a rock and fall in.\n\n"
    "It's much deeper than it looked!", this_player());
}

