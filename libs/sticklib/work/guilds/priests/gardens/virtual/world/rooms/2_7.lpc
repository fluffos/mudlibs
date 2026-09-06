/* Small hills */
// I hade to made these two rooms so that you can't get out of gardens
// by going southwest / southeast

#include "../gardens.h"
#include <virtual_room.h>

string *
do_desc() {
    string *tmp1;
    string *tmp2;

    tmp1= ({"You are following an animal trail up and over a hill.\n"});

    tmp2= ({
      "This small hill rises up out of the basin, giving a clear \
view of the surrounding areas. You feel that this surely must have \
been where Clerics of old came to meditate and worship Boccob."
    });

    return ({tmp1[random(sizeof(tmp1))]+tmp2[random(sizeof(tmp2))]});
}

void
create_virtual(){
    X = 2; Y = 7;
    set(ROOM_WD, WD_OUTDOORS);
    set_light_level(LT_LIGHTS);
    set_short("Small hill");

    set_virtual_exits(([
	"north":({0,-1}),
	"northeast":({1,-1}),
	"east":({1,0}),
	"south":({0,1}),
	"west":({-1,0}),
	"northwest":({-1,-1}),
      ]));

    //set_distant_look(1);
    set(SKIP_EXITS);

    set_random_desc(do_desc());

}
