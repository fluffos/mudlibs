#include <lib.h>
#include ROOMS_H

inherit LIB_ROOM;

void create() {
    room::create();
    SetAmbientLight(30);
    SetShort("Tea Room");
    SetLong("This is a cozy room with a table and several armchairs. There is a teapot and some teacups on the table. To the east is the manor foyer.");
    SetItems(([
        "teapot" : "This is a porcelain teapot. The tea inside it is cold. There are flower designs on the sides.",
        ({ "table", "tea table" }) : "This table is made of valuable oak, imported from the south.",
        ({ "chairs", "chair", "armchair" }) : "These are large, comfortable armchairs that look like they haven't been used in a long time.",
      ]));
    SetExits(([
        "east" : "/domains/lennarmanor/room/start",
      ]));

}
void init(){
    ::init();
}
