#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
 ::create();
   set_short("Top of the northwestern most point of the temple");
   set_day_long("This is the top of the northwestern most point of the "
     "turrets. A hole in the ground leads back down to the bottom floor "
     "of the turret. You can see the ground along the northwestern side of "
     "the temple. The rest of the turret is south and east. The top of a "
     "ladder pokes out of the hole."); 
   set_night_long("The night sky is dark blue with many yellow pin points "
     "in it. The moon sits in the sky above. The top of the turret isn't "
     "much higher than the rest of the temple and has no roof above it. "
     "From here, the northwestern side of the temple can be seen. A hole "
     "in the ground gives a way back down to the ground floor of the "
     "turret.");
   set_items(([
     "hole"  :"The very top of a ladder just barely pokes out of the hole.",
     "ladder":"The way back down.",
     "sky"   :"Sun and moon, star and cloud. The sky is completely visible "
              "all day long.",
     "turret":"This is the northwestern turret."
   ]));
   set_properties(([ "light" : 2, "night light" : 2, "outdoors" : 1 ]));
   set_exits(([
     "down"  : ROOMS"l1nw1",
     "east"  : ROOMS"l2nw2",
     "south" : ROOMS"l2nw3",
   ]));
}

void reset() {
 ::reset();
   if (!present("magician"))
     make(MOB"2t1");
}

