/* Light forest in with Hard woods */

#include "../gardens.h"
#include <virtual_room.h>

string *
do_desc() {
    string *tmp1;
    string *tmp2;

    tmp1=({"You are following an animal trail through a light forest. "});

    tmp2=({
      "The hard woods here are thin and some faint light passes \
through the trees to make travel easier. ",
      "The young trees in this area make traveling easier. You can almost \
feel what it must have been like before these gardens were abandon. ",
      "The peace of these woods is startling, making you wish you you could \
have come here before they were abandon. "
    });

    return ({tmp1[random(sizeof(tmp1))]+tmp2[random(sizeof(tmp2))]});
}

void
create_virtual(){
    set(ROOM_WD,WD_OUTDOORS);
    set_light_level(LT_LIGHTS);
    set_short("Light forest");
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
    set_random_desc(do_desc());
    add_random_object(sprintf("%d:%d:%s",
	1+random(2), 50, GARDEN_NPC "mini_orc"));
}
