#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Inside a large tower");
   set_long("A light cool mist fills the room, "
            "giving this place a cool and refreshing feel. "
            "The spiral staircase winds upwards, higher into "
            "the tower.");
   set_listen("default", "The sounds of work and muttering can be heard.");
   set_items(([ "staircase" : "It leads up, higher into the tower." ]));
   set_exits(([ "up" : ROOMS"tower4",
                "down" : ROOMS"tower2"]));
   set_property("light", 2);
   set_properties((["town" : 1, "indoors" : 1, "building" : 1])); 
}
/*
void reset() {
 ::reset();
   if (!present("soldier"))
      new(MOB"soldier")->move(this_object());
}
*/
