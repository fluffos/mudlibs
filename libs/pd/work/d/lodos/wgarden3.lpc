#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_properties((["town" : 1, "light" : 2, "forest" : 1,
                    "night light" : 1 ]));
   set_short("Northern corner of a small garden");
   set_day_long("The northwestern corner of the small garden "
     "surrounding the northern Lodian tower doesn't have much to it. "
     "A few hedges line the steppingstones leading both south and "
     "east. Daylight shines happily onto the garden, radiating an "
     "aura of calm and tranquility.");
   set_night_long("The night light does not hide much in this "
     "northern corner of the garden, for only a few hedges have "
     "been planted here. The rocky soil is rough to walk on, but "
     "easily distinguished from the smooth steping stones leading "
     "south and east. The moon bathes the garden in a dim light.");
   set_items(([
      "tower" : "The northern tower is southeast of here.",
      "stones": "Stepping stones are used to travel through the "
                "garden.",
      "aura"  : "The general area gives off a relaxing aura.",
      "light" : "Light splashes on the garden around you.",
      "hedges": "A few hedges line the stepping stones here."
   ]));
   set_exits(([ "south" : ROOMS"wgarden2",
                "east"  : ROOMS"ngarden"
   ]));
}

void reset() {
 ::reset();
   if (!present("maiden"))
     make(MOB"maiden");
}
