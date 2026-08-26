#include <lib.h>
#include ROOMS_H

inherit LIB_ROOM;

void create() {
    room::create();
    SetAmbientLight(30);
    SetShort("Library");
    SetLong("This is a tall room with floor to ceiling bookshelves lining every wall. To the east is an iron spiral staircase leading up to a balcony and a second level.");
    SetExits(([
        "west" : "/domains/lennarmanor/room/start",
      ]));

}
void init(){
    ::init();
}
