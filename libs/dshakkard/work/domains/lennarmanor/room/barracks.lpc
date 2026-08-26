#include <lib.h>
#include ROOMS_H

inherit LIB_ROOM;

void create() {
    room::create();
    SetAmbientLight(30);
    SetShort("Barracks");
    SetLong("This is a room filled with bunk beds. There are multiple soldiers in here, all wearing sharp, wickedly curved swords on their hips.");
    SetExits(([
        "southwest" : "/domains/lennarmanor/room/start",
      ]));

}
void init(){
    ::init();
}
