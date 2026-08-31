#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Climbing up a tower along the stairs");
   set_properties((["light" : 2, "indoors" : 1 ]));
   set_long("The stairs lead up and down through the tower. In this "
      "smaller section of the tower, a guard post has been set up, but "
      "for lack of large equipment, you guess it is only a temporary "
      "post.");
   set_exits(([ "up" : ROOMS"wtower4",
                "down" : ROOMS"wtower2"]));
   set_items(([
      "post" : "A temporary guard post has been set up in this room",
      "stairs" : "The stairs lead up and down, through the tower.",
      "tower" : "The tower reaches almost to the sky."
   ]));
}

void reset() {
 ::reset();
   if (!present("soldier")) {
     make(MOB"soldier");
     make(MOB"soldier2");
   }
   if (!present("knight"))
     make(MOB"knight");
}
