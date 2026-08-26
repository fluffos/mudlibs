#include <lib.h>
#include ROOMS_H

inherit LIB_ROOM;

void create() {
    room::create();
    SetAmbientLight(30);
    SetShort("Reception Hall");
    SetLong("TODO");
    SetExits(([
        "down" : "/domains/lennarmanor/room/start",
      ]));

}
void init(){
    ::init();
}
