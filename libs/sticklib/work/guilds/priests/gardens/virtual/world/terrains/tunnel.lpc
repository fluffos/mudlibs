/* Dark forest in with Hard woods */

#include "../gardens.h"
#include <virtual_room.h>

#define DESC1 ({ \
"You shouldn't get here. Inform Chopin.", \
})

#define DESC2 ({ \
"BUG", \
})

string
do_desc() {
    return sprintf("%s %s", ADESC(DESC1), ADESC(DESC2));
}

void
create_virtual(){
    set(ROOM_WD, WD_OUTDOORS);
    set_light_level(LT_LIGHTS);

    set_short("Tunnel");
    if(strstr(object_name(), "#") < 0) return;

    set_virtual_exits(([
	"north":({0,-1}),
	"northeast":({1,-1}),
	"east":({1,0}),
	"southeast":({1,1}),
	"south":({0,1}),
	"southwest":({-1,1}),
	"west":({-1,0}),
	"northwest":({-1,-1}),
      ]));

    //set_distant_look(1);
    set(SKIP_EXITS);
    set_long(do_desc());
}
