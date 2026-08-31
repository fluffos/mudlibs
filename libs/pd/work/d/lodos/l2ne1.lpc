#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
 ::create();
   set_short("On top of the northeastern turret");
   set_day_long("This is the top of the northeastern turret. Right to the "
     "west, the northwestern turret can be spotted. The platform atop the "
     "northeastern turret consists of three more rooms, in a square "
     "fashion above the turret itself. A ladder sticks out of a hole in "
     "the ground, leading back down to the bottom floor.");
   set_night_long("The night makes the hill the temple rests on look "
     "larger than it is. A hole in the center of the floor is the way back "
     "down to the ground floor of the northeastern turret. A ladder sticks "
     "out of the hole. Straight to the west, the northwestern turret can "
     "be seen.");
   set_items(([
     "turret" : "The northwestern turret is to the west.",
     "ladder" : "It sticks about a foot out of the hole, like a sore thumb.",
     "platform":"This is a platform of sorts, atop the northeastern turret."
   ]));
   set_properties(([ "light" : 2, "night light" : 2, "outdoors" : 1 ]));
   set_exits(([
     "down"  : ROOMS"l1ne1",
     "east"  : ROOMS"l2ne2",
     "south" : ROOMS"l2ne3",
   ]));
}

void reset() {
 ::reset();
   if (!present("magician"))
     make(MOB"2t1");
}

