#include <std.h>
#include <tirun.h>

inherit VAULT;

void create() {
  ::create();
  set_properties(([ "light" : 2,
                  "indoors" : 1
                 ]));
  set_short("South Guest Room");
  set_long("The room is VERY simple in nature. There are no frills here, but everything "
           "someone might need to be comfortable. A simple bid, a dresser and nightstand "
           "decorate the room.");
  set_smell("default","Clean. Everything smells of clean.");
  set_exits((["north" : ROOMS"houses/cookie5"]));
  set_door("south door", ROOMS"houses/cookie5", "north", "cookie_key");
}
