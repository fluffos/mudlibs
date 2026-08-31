
#include <std.h>
#include <saahr.h>

inherit HOUSE_ROOM;

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
    "The main path through town goes right past a light blue house here. "
    "All around the house are "
    "%^YELLOW%^br%^BOLD%^%^WHITE%^ig%^RED%^ht%^MAGENTA%^ly "
    "%^YELLOW%^co%^RED%^lo%^BLUE%^red%^WHITE%^ "
    "fl%^MAGENTA%^ow%^BLUE%^ers%^RESET%^ "
    "and a large herb garden. The house itself stands taller than the rest "
    "of those in town, with a large shade tree practically touching the "
    "front porch."
  );
  set_items(([
    "path" : "The path leads east and west and is well used.",
    "town" : "The town is made up of several small houses.",
    "house" : "It's very tall, two stories by the look of it.",
    "flowers" : "A few different kinds, in several colors.",
    "tree" : "A tall, thick oak tree with many leaves.",
    "porch" : "The porch is covered and furnished with two rocking chairs.",
  ]));
  set_smell("default", "A gentle flowery scent fills the air.");
  set_smell("flowers", "They smell very sweet.");
  set_smell("herbs", "Whoa! Rather pungent!");
  set_exits(([
    "north":VPROOMS"town14_7",    
    "east":VPROOMS"town15_8",    
    "south":VPROOMS"town14_9",    
    "west":VPROOMS"town13_8",
    "enter house":VPROOMS"house14_8"
  ]));
  check_door();
}


