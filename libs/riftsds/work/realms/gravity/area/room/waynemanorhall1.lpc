#include <lib.h>
#include ROOMS_H

#include "/realms/gravity/area/customdefs.h"

inherit LIB_ROOM;

void create() {
    room::create();
    SetAmbientLight(30);
    SetShort("Wayne Manor Hallway");
    SetLong("The hallway in Wayne Manor is adorned with rich mahogany paneling and luxurious Persian rugs. Dim, antique sconces cast a warm glow on the walls, lined with portraits of the Wayne ancestors. The air is thick with the scent of polished wood and old money. A sense of history and opulence permeates the space, making it both inviting and imposing.");
    SetExits(([
        "south" : "/realms/gravity/area/room/waynemanorhall2",
      ]));

}

void init(){
    ::init();
}
