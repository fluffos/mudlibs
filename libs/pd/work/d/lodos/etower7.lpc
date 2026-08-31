#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("In front of open windows");
   set_properties((["light" : 2]));
   set_properties((["town" : 1, "indoors" : 1, "building" : 1]));
   set_long("Several windows line the western wall, letting tree "
      "leaves and branches into the tower. A few fallen leaves lie on "
      "the ground here. The windows have been opened for fresh air by "
      "one of the servants.");
   set_exits(([ "down" : ROOMS"etower6",
                "north" : ROOMS"etower8"]));
   set_items(([
      "leaves" : "A few brown leaves lie on the ground",
      "windows" : "All the windows are open.",
      "branches" : "You can see a bird nest in one of them!",
      "wall" : "Windows line the western wall, above the stairs.",
      "nest" : "Little baby birds are crawling along the branch"
   ]));
}

void reset() {
 ::reset();
   if (!present("bluejay"))
     make(MOB"jay");
}
