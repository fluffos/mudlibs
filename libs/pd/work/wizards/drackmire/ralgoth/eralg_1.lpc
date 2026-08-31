#include <std.h>
#include "ralgoth.h"
inherit ROOM;

void create() {
 ::create();
set_short("East Ralgoth Street");
    set_property("town", 1);
    set_property("indoors", 1);
    set_long(
	"East Ralgoth Avenue runs through the middle of Ralgoth, alongside "
	"the river that provides the fortress water.  To the north of the "
	"street lies the Merchant District, while to the south lies the "
	"magic district.  Although it is one of the main thoroughfares "
	"of Ralgoth, it is sparsely travelled, due to the fear which "
	"grips the city." );
    set_listen("default", "An eerie silence pervades the street.");
    set_exits( 
              (["west" : RALROOMS"square",
                "east" : RALROOMS"eralg_2",
		]) );

    set_property("light", 1);
    set_property("night light", 1);
    set_items(
        (["road" : "Drolmire Street runs east to the fortress wall.",
          "river" : "A river flows through the center of the fortress, "
	"through the east and west walls.  It bends just west of here "
	"providing a natural island for the city square."]) );
}
