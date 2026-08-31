#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_properties((["outdoors" : 1, "light" : 2,
	"night light" : 1]));
    set_short("Before a magnificent temple");
    set_day_long("The sun's light relects off of the diamonds lining the doorway "
      "of the temple here. Tall doors to a beautiful and illustrious temple are "
      "here, at the very top of this hill. From this vantage point, almost all of "
      "the town to the south and surrounding area can be seen.");
    set_night_long("Moonlight bathes the beautiful and illustrious temple here. "
      "Diamonds have been afixed to the temple's tall, wooden doors. Dim light "
      "from both the stars and moon shine onto this small hill that has an "
      "excellent view over the darkened town of Lodos.");
    set_items(([
	"temple" : "The temple is right here, it is awe inspiring and breath "
	"taking.",
	"town"   : "Lodos is a fairly small healing town of clerics and priests.",
	"hill"   : "This hill is set in the center of a path, that leads up to the "
	"temple.",
	"path"   : "The old dirt road leads only south, towards the town of Lodos."
      ]));
    set_exits(([ "enter" : ROOMS"l1m8",
	"south" : ROOMS"npath4",
      ]));
}

void reset() {
    ::reset();
    if(!present("pygmy")) {
	make(MOB"smurf2");
	make(MOB"smurf1");
    }
}

