#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_properties((["indoors" : 1, "light" : 2,
                    "night light" : 1]));
   set_short("East of the temple entrance");
   set_day_long("This room is just east of the large wooden-doored entrance to "
     "this magnificent temple. Just southeast a spire reaches just above the "
     "rest of the temple, probably an outlook of some sort. A doorway in the onyx "
     "walls leads west, another north and yet another into the turret "
     "southeast.");
   set_night_long("Shadows play across the room, with candle light flickering in "
     "from the north and west. A marble passage goes southeast into an outlook "
     "of some sort that reaches just above the tower. The night air is cool within "
     "the confines of the temple. The onyx walls have been cut out for several "
     "windows on the southern wall.");
   set_items(([
     "windows" : "Stained glass windows line the southern wall.",
     "walls"   : "Onyx walls stand proud, holding up the temple.",
     "floor"   : "Tiled floor, looks marble?",
     "turret"  : "The southeast turret is one of the four lookouts on the "
                 "corners of the temple."
   ]));
   set_exits(([ "west"       : ROOMS"l1m8",
                "north"      : ROOMS"l1m6",
                "southeast"  : ROOMS"l1se1"
   ]));
}

void reset() {
 ::reset();
   if (!present("man"))
     make(MOB"oldrobed");
}

