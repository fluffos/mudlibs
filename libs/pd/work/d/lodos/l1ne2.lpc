#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
 ::create();
   set_short("Northeastern most point of the entire temple");
   set_day_long("This is the very northeastern most point of the entire "
     "temple; both the main temple and of the turrets. The white tiled "
     "floors lead west and south. Walls of white and grey onyx line the "
     "turret.");
   set_night_long("This is the northeastern most point of the entire "
     "temple. This part of the turret is fairly well lit compared to the "
     "nighttime surroundings. The walls and the tiled floor are both the "
     "same color now; a dark grey and where the shadows are heaviest, "
     "black.");
   set_items(([
     "turret" : "You are currently in the northeastern most turret of the "
                "temple.",
     "walls"  : "The walls are made of a pure white and light grey onyx."
   ]));
   set_properties(([ "light" : 2, "night light" : 1, "indoors" : 1 ]));
   set_exits(([
     "up"    : ROOMS"l2ne2",
     "west"  : ROOMS"l1ne1",
     "south" : ROOMS"l1ne4",
   ]));
}

void reset() {
 ::reset();
   if (!present("sage"))
     make(MOB"t2");
}
