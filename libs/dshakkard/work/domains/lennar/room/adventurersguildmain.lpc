#include <lib.h>
#include ROOMS_H

inherit LIB_ROOM;

void create() {
    room::create();
    SetAmbientLight(30);
    SetShort("Adventurer's Guild");
    SetLong("This is a medium sized room, about 10 feet square. There is a low table to the north, in front of a closed, locked door. Several people mill around, with wicked-looking weapons strapped to themselves.");
    SetItems(([
        ({ "statue", "large statue" }) : "It's a large statue of a portly middle-aged man sitting on a throne. His face looks stern.",
      ]));
    SetInventory(([
        "/domains/lennar/npc/odogarfield" : 1,
      ]));
    SetExits(([
        "south" : "/domains/lennar/room/mainstreet1",
      ]));

    SetClimate(0);

}
void init(){
    ::init();
}
