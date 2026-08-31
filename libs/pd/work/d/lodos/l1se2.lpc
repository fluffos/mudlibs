#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
 ::create();
   set_short("A room on the bottom floor of the southeastern turret");
   set_day_long("This is one of four of the rooms on the bottom floor of "
     "the southeastern turret surrounding the temple. This turret is "
     "connected to the temple just to the west of here. Two doorways are "
     "attached to this room, one west and another south.");
   set_night_long("The only light in this dark room comes from a hole in "
     "the ceiling right in the middle of the room. There is practically no "
     "light here, making it very difficult to make out anything, no matter "
     "how good your vision is. Two doorways lead out of this room, one "
     "west and the other south.");
   set_items(([
     "doorways" : "Two doorways; south and west, both lead to other parts "
                  "of the turret.",
     "hole"     : "The main source of light is a hole in the ceiling. The "
                  "hole connects this room to the higher level of the "
                  "turret.",
   ]));
   set_properties(([ "light" : 2, "night light" : 0, "indoors" : 1 ]));
   set_exits(([
     "up"    : ROOMS"l2se2",
     "west"  : ROOMS"l1se1",
     "south" : ROOMS"l1se4",
   ]));
}

void reset() {
 ::reset();
   if (!present("sage"))
     make(MOB"t2");
}
