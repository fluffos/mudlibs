#include <std.h>
#include <tirun.h>
inherit ROOM;
void create() {
 ::create();
   set_property("light", 2);
   set_property("indoors",1);
   set("short", "The Adventurers Hall");
   set("long",
        "Welcome to the Adventurers Hall. A hallway leading east enters the greater "
        "hall.  A doorway to the south leads to the Tirun Market Square.  The room is "
        "well furnished with tapestries on the walls, ornate rugs on the floors, gold "
        "lamps on the walls, and a few chairs scattered about.  The archway to the east has been boarded up.");
   set_items(
        (["lamps" : "Gold lamps light up this room.",
          "tapestries" : "Woven works of art depicting various sceens of battle.",
          "rugs" : "Intracately patterned woven rugs cover the floor.",
          "chairs" : "Expensive carved chairs of a golden color wood.",
   ]));
   set_exits( 
             (["out" : ROOMS "square2",
      "up" : ROOMS "locker",
         "east" : ROOMS "adv_hall",
    ]) );
}
