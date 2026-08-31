#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Inside the servant's quarters");
   set_properties((["light" : 1]));
   set_properties((["town" : 1, "indoors" : 1, "building" : 1])); 
   set_long("Much like many of the other smaller rooms in the tower, the "
       "servant's quarters is a small and windowless room, making light "
       "on the dim side. The floor is old and shows evidence of constant "
       "use. A couple straw cots have been lined up against the wall.");
   set_exits(([ "south" : ROOMS"ntower4" ]));
   set_items(([
      "room" : "It is small and the lighting is dim.",
      "windows" : "What windows? There are no windows. Can't you read?",
      "floor" : "Many footprints mark the floor as being in constant use.",
      "cots" : "The straw cots are lined up against the wall."
   ]));
}

void reset() {
 ::reset();
   if (!present("servant")) {
     make(MOB"servant");
     make(MOB"servant");
     make(MOB"servant");
   }
}
