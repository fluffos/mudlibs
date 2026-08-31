#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Inside a large tower");
   set_long("The stairway that you are on leads up and down, higher and "
      "lower into the tower. The walls are circular and tiled. A small "
      "doorway leads south, into somebody's chambers.");
   set_listen("default", "The sounds of work and muttering can be heard.");
   set_items(([ "staircase" : "It leads up, higher into the tower.",
      ({ "doorway", "door" }):"Just an open doorway with no actual door." ]));
   set_exits(([ "up" : ROOMS"tower5",
                "south" : ROOMS"alchem",
                "down" : ROOMS"tower3"]));
   set_properties((["town" : 1, "indoors" : 1, "building" : 1])); 
   set_property("light", 2);
}
