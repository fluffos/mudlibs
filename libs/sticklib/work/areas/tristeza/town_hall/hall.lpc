#include <room.h>

#include "DEFS.h"
#include "/areas/tristeza/DEFS.h"

#include <city_name.h>

void
create_room()
{
    set(IN_CITY);
    set(NO_PK);
    set_outdoors(WD_INDOORS);
    set_light_level(LT_LIGHTS);
    set_short("Town Hall");
    set_long(
      "This is the main hall of the "+CITY_NAME+" town hall. It looks quite\
 impressive with its tall marble pillars and mosaic floor. The high ceiling\
 is painted with a fresco that would make even Michelangelo proud of it.\
 Through the large windows you can hear noises from the market square."
    );
    set_exits(([
	"north"	: THALL_ROOMS "agency",
	"south"	: CITY_DIR+"S6_6",
	"southwest" : THALL_ROOMS "museum",
	"west" : THALL_ROOMS "secr_room",
      ]));
    set_items(([
	({ "pillar","pillars","marble pillars","tall marble pillars"}) :
	"Tall marble pillars support the high ceiling.",
	({ "floor", "mosaic" }) :
	"The floor has a mosaic pattern that looks three-dimensional.",
	({ "fresco","ceiling" }) : "The fresco pictures the creation of the world."
      ]));
}
