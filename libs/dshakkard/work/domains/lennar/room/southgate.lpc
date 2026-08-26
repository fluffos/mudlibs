#include <lib.h>
#include ROOMS_H

inherit LIB_ROOM;

void create() {
    room::create();
    SetAmbientLight(30);
    SetShort("South Gate");
    SetLong("This is a large arch with thick wooden doors on either side. They look like they haven't closed in a long time. Guards and merchants mill about here. To the north is the rest of Lennar, and to the south are the Northern Wastes.");
    SetExits( ([
        "north" : "/domains/lennar/room/citystreet1",
        "south" : "/domains/northernwastes/virtual/wastes/1,0",
      ]) );

    SetClimate("indoors");

}
void init(){
    ::init();
}
