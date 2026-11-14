/* The Orphan's home of NF City. Usually the Blues Brothers are here.*/
#include <moving.h>

#include "path.h"

inherit "std/room";

object scroll;   // to hide one of Joern's scrolls

look_floor() {
    if (scroll) {
    return "You find nothing.\n";
    }
    scroll=clone_object(SCROLLS("pipeweed"));
    scroll->move(this_object(),M_SILENT);
    return "You found a scroll on the floor. Just get it.\n";
}

void create() {
           ::create();
           SetIntShort("An Orphan's home");
           SetIntLong(
"You are standing inside an old orphan's home. The walls are rotten but "+
"there still live children in this shabby building. Many eyes stare at "+
"you out of some small beds standing in two rows in front of you.\n"+
"These eyes belong to children, but there's no hope to see in them.\n"+
"You can leave the home to the north.\n");
           AddExit("north", "/d/archwiz/common/room/city/row6");
           AddItem("/d/archwiz/randyandy/mon/jake",1);
           AddItem("/d/archwiz/randyandy/mon/elwood",1);
           AddDetail("beds", "Small, shabby beds. They seem to be very old.\n");
           AddDetail(({"ground","floor"}),#'look_floor);
           AddDetail("children", "All children look at you with sad eyes.\n");
           AddDetail("child", "You look at one of the dirty children in their beds.\nYou feel sad and guilty, but you can't do anything to \nhelp these poor creatures.\n");
           SetIndoors(1);
           reset();
}

reset() {
  ::reset();
  scroll=0;
}
