#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Climbing up a tower along the stairs");
   set_properties((["light" : 2, "indoors" : 1 ]));
   set_long("The tower leads up and back down to the ground. Through a "
      "window, you can see people walking around below. The paint on "
      "the walls is flaking and old. This part of the tower looks very "
      "old.");
   set_exits(([ "up" : ROOMS"wtower5",
                "down" : ROOMS"wtower3"]));
   set_items(([
      "tower" : "This part looks at least a couple hundred years old.",
      "window": "You can see the street below through the window.",
      "people": "A cruel through crosses your mind.. spit on them.",
      "below" : "The street below is dirt. Several people walk around."
   ]));
}

void reset() {
 ::reset();
   if (!present("knight"))
     make(MOB"knight");
   if (!present("squire"))
     make(MOB"squire");
}

int spit(string str) {
   if (!str || str != "on people") return notify_fail("Spit on whom?\n");
   write("You spit on the people below!");
   tell_room(environment(this_player()), "You hear people cursing below.");
   return 1;
}

void init() {
 ::init();
   add_action("spit", "spit");
}
