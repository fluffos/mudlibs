
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
    "Some bushes lie just off the path, obviously trimmed into "
    "square shapes. Past the bushes sits a log cabin with the "
    "beginnings of a lawn growing around it. The town square "
    "can be seen to the southeast."
  );
  set_items(([
    "bushes" : "Neatly trimmed, dark green bushes. Four of them "
      "stand in a row.",
    "cabin" : "The cabin is made of logs cut and inserted together. "
      "Some windows can be seen, as well as the front door.",
    "windows" : "The sun glints off of them.",
    "door" : "The door is also made of logs.",
    "lawn" : "Small wisps of grass growing in a large area.",
    "square" : "The town square is just visible.",
  ]));
  set_exits(([
    "east":VPROOMS"town12_7",
    "southeast":VPROOMS"town12_8",
    "south":VPROOMS"town11_8",
    "west":VPROOMS"town10_7",
    "enter house":VPROOMS"house11_7"
  ]));
  check_door();
}


