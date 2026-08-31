#include <std.h>
#include <tirun.h>

inherit ROOM;

void create() {
  ::create();
  set_properties(([ "light" : 2,
                  "indoors" : 1
                 ]));
  set_short("Dining Room");
  set_long("The Dining room! A candle lit room spans much deeper than you think the small "
           "room would be capable of. The Dining room table is set for 4 people, gleeming "
           "silverwear, the finest china, Perhaps they are expecting guests!");
  set_smell("default","Spices and baked bread smells fill the room.");
  set_exits((["east" : ROOMS"houses/cookie2"]));
}
