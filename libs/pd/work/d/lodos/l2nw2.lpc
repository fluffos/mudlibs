#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
 ::create();
   set_short("Atop the northwestern turret");
   set_day_long("This platform atop the northwestern turret is the lookout "
     "for the temple. The northeastern turret can be seen from here, "
     "straight across to the east. The sky is a bright blue, with an "
     "occasional cloud crossing the sky. The sun shines brightly onto this "
     "turret.");
   set_night_long("The moon and stars are the only things in the sky for "
     "quite a while, though a single cloud or two crosses the sky occasion"
     "ally. A second turret can be seen east. There is a narrow area of "
     "land between the two turrets, just north of the temple. The turret "
     "isn't really too much higher than the temple itself.");
   set_items(([
     "turret" : "A second turret, the northeastern, can be seen east.",
     "sky"    : "Not many clouds in the sky."
   ]));
   set_properties(([ "light" : 2, "night light" : 2, "outdoors" : 1 ]));
   set_exits(([
     "down"  : ROOMS"l1nw2",
     "west"  : ROOMS"l2nw1",
     "south" : ROOMS"l2nw4",
   ]));
}

void reset() {
 ::reset();
   if (!present("magician"))
     make(MOB"2t2");
}

