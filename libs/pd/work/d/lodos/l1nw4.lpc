#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
 ::create();
   set_short("Northwestern turret of the temple");
   set_day_long("High enough to see the surrounding lands around the "
     "temple, the turrets serve as a sort of guard post for the temple. "
     "Tiled floors go southeast, north, and west to other parts of the "
     "turret and the southeastern into the main part of the temple.");
   set_night_long("Shadowy night time tiles lead north and west to other "
     "sections of the northwestern turret. The turret is just high enough "
     "to view the surrounding land about the temple, making this a sort "
     "of guard post.");
   set_items(([
     "floor"  : "The floor is tiled, much like the rest of the temple.",
     "turret" : "A guard post of sorts, the turret is not much higher "
                "than the temple itself.",
     "post"   : "Yup.. I said guard post. g-u-a-r-d p-o-s-t. guard post."
   ]));
   set_properties(([ "light" : 2, "night light" : 1, "indoors" : 1 ]));
   set_exits(([
     "up"        : ROOMS"l2nw4",
     "north"     : ROOMS"l1nw2",
     "west"      : ROOMS"l1nw3",
     "southeast" : ROOMS"l1m1"
   ]));
}

void reset() {
 ::reset();
   if (!present("apprentice"))
     make(MOB"t4");
}
