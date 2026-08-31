#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_properties(([ "town" : 1, "light" : 2, "night light" : 1,
     "forest" : 1 ]));
   set_short("Inside a comfy litle house");
   set_day_long("This is the inside of a well kept, comfortable little "
     "house. Light streams in through the open windows and the door is "
     "wide open, letting the fresh air in from the garden. A doorway, "
     "though there is no actualy door leads north, probably into the "
     "kitchen. Another doorway leads west, into a bedroom.");
   set_night_long("This is the inside of a well kept, comfortable little "
     "house. The windows have been left open to allow the cool night "
     "air into the house. The door is open, almost as if a guest is "
     "expected. Candles and lanterns light up the house. Two doorways, "
     "besides the outside exit are here. The northern leads into a "
     "kitchen, and the western into a bedroom.");
   set_items(([
     "foo" : "bar",
     "bar" : "If you think this is the bar, you're dead wrong.",
     "windows" : "The windows are opened.",
     "kitchen" : "The kitchen is to the north, it looks messy from here.",
     "bedroom" : "An unkept bedroom is to the west.",
     "house" : "Its pretty nice, but messy."
   ]));
   set_exits(([ "out" : ROOMS"garden",
                "west" : ROOMS"bedroom",
                "north" : ROOMS"kitchen" ]));
}

void reset() {
 ::reset();
   if (!present("pipiel"))
     make(MOB"pipiel");
}
