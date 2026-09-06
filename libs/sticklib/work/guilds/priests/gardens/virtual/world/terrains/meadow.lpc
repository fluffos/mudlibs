
/* A beautiful meadow with wild flowers */

#include "../gardens.h"
#include <virtual_room.h>

string *
do_desc() {
    string *tmp1;
    string *tmp2;

    tmp1= ({"You are wandering in a meadow at the center of the basin. "});

    tmp2= ({
      "This meadow contains many beautiful flowers and herbs. It gives you \
feelings of calm and inner peace. ",
      "The flowers in this meadow are colorful and inviting. You realize \
that surely this place has not changed since the time these gardens \
were abandon. ",
      "The flowers and herbs here are very appealing to your eyes. \
You feel a sense of peace that could come only from Boccob. "
    });

    return ({tmp1[random(sizeof(tmp1))]+tmp2[random(sizeof(tmp2))]});
}

void
create_virtual(){
    set(ROOM_WD, WD_OUTDOORS);
    set_light_level(LT_LIGHTS);
    set_short("Beautiful meadow");
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

    set_items(([
	"flowers": "These colorful flowers smell very good.",
	"herbs": "The herbs smell very pungent, maybe they have \
medicinal properties",
      ]));

    set_random_desc(do_desc());
    add_random_object(sprintf("%d:%d:%s",
	2+random(3), 40, GARDEN_NPC "mini_gnome"));
}
