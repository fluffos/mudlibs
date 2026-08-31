#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 ::create();
   set_properties(([ "light" : 3 ]));
   set_short("Entrance to the business district");
   set_day_long(
     "This small cull de' sac leads into the business district of Tirun. There "
     "are three shops here. A shop with a sign depicting many different items "
     "and objects is south. The town weapon shop is west and the armour shop is "
     "located east of this part of the road. This cull de' sac connects to Honin "
     "Road north."
   );
   set_night_long(
     "A darkened cull de' sac leads into the Tirun business district. Moonlight "
     "shows three buildings here, each with a sign in front of it. There is a "
     "shop west and one east. The third shop is to the south. A sign in front of "
     "the western building depicts many weapons and the shop to the south shows "
     "a variety of different items. The sign to the east is covered in shadows, "
     "and is unreadable."
   );
   set_items(([
     "signs" : "Three signs, one in front of each shop.",
     "shops" : "A weaponry, general supply shop, and an armoury.",
     "cull de' sac" : "A very small, dead-end road leading into the business "
                      "district."
   ]));
   set_exits(([
     "north" : ROOMS"whonin2",
     "south" : ROOMS"supply",
     "east"  : ROOMS"armour",
     "west"  : ROOMS"weapon"
   ]));
}

void reset() {
 ::reset();
   if (!present("horse")) {
     new(MOB"horse")->move(this_object());
     new(MOB"horse")->move(this_object());
   }
}
