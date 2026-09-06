/* Dark forest in with Hard woods */

#include "../gardens.h"
#include <virtual_room.h>

#define DESC1 ({ \
"You are swimming in a small lake.", \
})

#define DESC2 ({ \
"The water is clear." \
})

string
do_desc() {
    return sprintf("%s %s", ADESC(DESC1), ADESC(DESC2));
}


void
create_virtual(){
    set(ROOM_WD, WD_OUTDOORS);
    set_light_level(LT_LIGHTS);

    set_short("Small lake");
    if(strstr(object_name(), "#") < 0) return;

    //    set_moving_command("swim", "swims", "swims in");
    // This doesn't work (?!)
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
    /*
	add_random_object(sprintf("%d:%d:%s",
	    1+random(2), 30, GARDEN_NPC "mini_d_elf"));
    */
}
