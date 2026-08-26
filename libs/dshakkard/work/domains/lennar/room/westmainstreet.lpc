#include <lib.h>
#include ROOMS_H

inherit LIB_ROOM;

void create() {
    room::create();
    SetAmbientLight(30);
    SetShort("East Main Street");
    SetLong("This is a long street that bisects Lennar from east to west. To the east is a city square with a large statue in the center. To the north, a large mansion looms over the city. To the west is the great arch of the Western Gate, which leads to the rest of the Northern Confederacy.");
    SetItems(([
        ({ "statue", "large statue" }) : "It's a large statue of a portly middle-aged man sitting on a throne. His face looks stern.",
      ]));
    SetExits(([
        "east" : "/domains/lennar/room/everettsquare",
      ]));

    SetClimate("indoors");

}
void init(){
    ::init();
}
