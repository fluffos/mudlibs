#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Climbing up a tower along the stairs");
   set_properties((["light" : 2, "indoors" : 1 ]));
   set_long("This small guard post in the tower even has chairs set "
      "up for the guards to sit in. The stairs twist a little here, "
      "but continue both up and down. The tower only stands a bit higher.");
   set_exits(([ "up" : ROOMS"wtower8",
                "down" : ROOMS"wtower6"]));
   set_items(([
      "post" : "The guard post has been set up for a higher rank than usual.",
      "chairs" : "The metal chairs are better than nothing..",
      "stairs" : "The stairs have a slight twist in them here.",
      "tower" : "It is only a little bit taller."
   ]));
}

void reset() {
 ::reset();
   if (!present("knight"))
     make(MOB"knight");
   if (!present("soldier"))
     make(MOB"soldier2");
   if (!present("paladin")) {
     make(MOB"paladin");
     make(MOB"paladin");
   }
}
