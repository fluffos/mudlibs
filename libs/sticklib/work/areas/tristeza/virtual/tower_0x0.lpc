#include "../DEFS.h"
#include <room_defs.h>

inherit	TRISTEZA_ROOM_C;

void
create_room()
{
    ::create_room();
    set(ROOM_WD, WD_INDOORS);
    set_short("Tower bottom");
    set_long("You are on the bottom of a tower. There is dust everywhere.\
 The tower hasn't been used since the great orc wars.");
    add_item("dust", "It's just ordinary dust.");
    add_exit("up" , CITY_DIR + "T_NW2");
    add_exit("southeast", CITY_DIR+"S1_1");
}
