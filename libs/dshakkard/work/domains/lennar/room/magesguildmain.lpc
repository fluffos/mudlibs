#include <lib.h>
#include ROOMS_H

inherit LIB_ROOM;

void create() {
    room::create();
    SetAmbientLight(30);
    SetShort("Mage's Guild");
    SetLong("This is a large room, that seems much larger than the outside would suggest. A mystical aura surrounds you. There is a small table to the west which seems to sell goods. To the south is the portal room.");
    SetItems(([
        ({ "statue", "large statue" }) : "It's a large statue of a portly middle-aged man sitting on a throne. His face looks stern.",
      ]));
    SetExits(([
        "north" : "/domains/lennar/room/mainstreet1",
      ]));

    SetClimate("indoors");

}
void init(){
    ::init();
}
