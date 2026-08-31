
#include <std.h>
#include <saahr.h>

inherit ROOM;

string look_below();

void create() {
  ::create();
  set_properties(([
    "light":2,
    "indoors":1,
    "town":1
  ]));
  set_short("inside a house");
  set_long(
    "The loft is pretty bare. A waist high railing lines the front edge. "
    "A low pallet-style bed spreads along the middle of the floor. "
    "Below, the rest of the house can be seen."
  );
  set_items(([
    "railing" : "Several verticle poles hold up a series of boards. "
      "The railing no doubt serves to keep sleepers from rolling "
      "off the edge.",
    "bed" : "The bed is made of a straw-stuffed cloth perched on a "
      "wooden frame.",
    "below" : (: look_below :),
  ]));
  set_exits(([
    "down":VPROOMS"house11_9"
  ]));
}

void reset() {
  ::reset();
}

string look_below() {
  object room = load_object(query_exit("down"));
  string msg, tmp;
  if (!room)
    return "Nothing can be seen.";
  msg = room->query_long(0) + "\n";
  tmp = room->describe_living_contents( ({}) );
  if (strlen(tmp))
    msg += tmp + "\n";
  tmp = room->describe_item_contents( ({}) );
  if (strlen(tmp))
    msg += tmp + "\n";
  return msg;
}

