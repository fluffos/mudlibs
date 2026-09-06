/* Cliffs at the edge of impenatrable Mountains */

#include "../gardens.h"
#include <virtual_room.h>

string *
do_desc() {
    string *tmp1;
    string *tmp2;

    tmp1= ({"You are on the talus slope of some steep mountains. "});

    tmp2= ({
      "The valley lays out before you and you can see a meadow \
to the center. Animal trails go in several directions. ",
      "The talus slope ends at a light forest, with the whole basin lying \
beneath you. The signs of animals in the area are apparent from the \
many trails. ",
      "The basin spreads out beneath you, and the sheer walls of \
impassible mountains are behind you. "
    });

    return ({tmp1[random(sizeof(tmp1))]+tmp2[random(sizeof(tmp2))]});
}

void
create_virtual(){
    set(ROOM_WD, WD_OUTDOORS);
    set_light_level(LT_LIGHTS);
    set_short("Talus slope");
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
	1+random(2), 20, GARDEN_NPC "mini_giant"));
}
