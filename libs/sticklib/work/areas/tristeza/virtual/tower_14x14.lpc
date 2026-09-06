#include <areas.h>
#include <generic_items.h>
#include "../DEFS.h"
#include <room_defs.h>

inherit TRISTEZA_ROOM_C;

void
create_room()
{
    ::create_room();
    set(ROOM_WD, WD_INDOORS);
    set_short("Tower bottom");
    set_long("You are on the bottom of a tower. There is dust everywhere.\
 The tower hasn't been used since the great orc wars.");
    add_item("dust", "It's just ordinary dust.");
    add_exit("up", CITY_DIR + "T_SE2");
    add_exit("northwest", CITY_DIR+"S13_13");
    add_object( ({ GENERIC_SIGN,
	({ "set_name", "sign" }),
	({ "set_id", "sign" }),
	({ "set_short", "A nice clean sign" }),
	({ "set_long", "A very nice, very clean sign. "+
	  "You want to read it..." }),
	({ "set_read_msg", "It reads:\n\n  You are about to "+
	  "enter the catecomb's of "+CITY_NAME+".\n  Please "+
	  "mail Jack all bugs, typos, etc.\n\n  ENJOY!" }),
      }), 0, 1 );
}
