#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_properties((["indoors" : 1, "light" : 2,
                    "night light" : 1]));
   set_short("Within the doors of a magnificent temple");
   set_day_long("This is the main chamber, the entranceway, of a magnificent "
     "temple. To the south are two large, wooden doors leading outside of this "
     "temple. Tiled floors meet diamond studded doorways and giant marble pillars "
     "before ending at grey and white onyx walls. Something has been inscribed "
     "in the onyx wall above the wooden doors.");
   set_night_long("The light in the main chamber, entranceway, of this magnificent "
     "temple is dim in the nighttime light. Only a small ammount of moonlight "
     "enters by means of several stained glass windows along the wall near the "
     "two large, wooden doors leading outside. Directly above the exitway doors, "
     "is an inscription in the white and grey onyx wall.");
   set_items(([
     "inscription" : "The inscription reads in a tongue you are not familiar with, "
                     "'Annar Tilin', and a second reads, 'Shir att sol Annari'",
     "floor"       : "Tiled floors head down every passage and in every room.",
     "walls"       : "The walls are made of a wonderful onyx, above one wall is "
                     "an inscription.",
     "windows"     : "Stained glass windows depict holy scenes."
   ]));
   set_exits(([ "west" : ROOMS"l1m7", // Note: l1m7.. see /d/lodos/plan
                "east" : ROOMS"l1m9", // l1m7 would be level 1 middle, 7, etc.
                "out"  : ROOMS"npath5"
   ]));
}

void reset() {
 ::reset();
   if (!present("guard"))
     make(MOB"gangel");
}

