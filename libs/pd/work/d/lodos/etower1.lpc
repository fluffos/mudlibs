#include <lodos.h>
#include <std.h>
inherit VAULT;
void look_door();

void create() {
 ::create();
   set_short("At the base of a large tower");
   set_properties((["light" : 2, "indoors" : 1, "town" : 1,
     "building" : 1]));
   set_long("The eastern tower along the road leads up by means of a "
      "spiraling and twisted staircase. The small, wooden door leads "
      "west, onto a small, old, worn out dirt path. A small window has "
      "been placed directly above the door.");
   set_exits(([ "up" : ROOMS"etower2",
                "west" : ROOMS"ntown7"]));
   set_items(([ "door" : (: look_door() :) ]));
   set_door("door", ROOMS"ntown7", "west", "");
}

void look_door() {
    if(query_open("door 2")) write("It is open.");
    else write("It has been closed.");
}

void reset() {
 ::reset();
   if (!present("soldier")) {
     make(MOB"soldier");
     make(MOB"soldier");
     make(MOB"soldier");
   }
}
