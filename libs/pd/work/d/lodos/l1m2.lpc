#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_properties((["indoors" : 1, "light" : 2,
                    "night light" : 1]));
   set_short("A 'T' interesection at the north end of a temple");
   set_day_long("At the very northern room of the temple, a 'T' intersection "
     "is formed by doorways connecting east, west, and south. All three doorways "
     "lead into a seperate part of the temple much like this one. The only thing "
     "on the onyx walls besides stained glass windows on the north are candles "
     "that float along the edge of the southern corners of the doorway.");
   set_night_long("Candles float along the southern wall, near a doorway, giving "
     "light to the otherwise dark night. Stained glass windows line the northern "
     "wall. A doorway to the east, west, and one to the south form a sort of '"
     "T' intersection here.");
   set_items(([
     "windows" : "Stained glass windows line the northern wall.",
     "candles" : "They float magically along the southern wall.",
     "intersection":"A 'T' intersection is formed here."
   ]));
   set_exits(([ "west"  : ROOMS"l1m1",
                "east"  : ROOMS"l1m3",
                "south" : ROOMS"l1m5"
   ]));
}

void reset() {
 ::reset();
/*   if (!present("healer"))
     make(MOB"healer");*/
}

