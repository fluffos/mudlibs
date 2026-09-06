#include <room.h>
#include <door_defs.h>

#include "dirs.h"

object ob;

void
create_room()
{
    set_short("Stone-walled room");
    set_long(
      "This is a small stone-walled room. The roof seems to be made of "+
      "another material. A continual light spell lights the place.");
    set_light_level(LT_LIGHTS);
    set(ROOM_WD,WD_INDOORS);
    set(ROOM_GUILD);
    // Let 'em get out from here
    //set(PREVENT_TELEPORT);
    set(YES_PK);

    add_item(({ "roof" }),
      "The roof has a large trapdoor. But it seems to be very strong, barred "+
      "and locked. You won't escape through that.");

    if ((ob = clone_object(DOOR_FILE))) {
	ob->add_door( ({
	    "It is a heavy iron door.\n",
	    "It is a heavy iron door.\n" }),
	  "east", GDIR + "rooms/tunnels", "fine steel",
	  "thief_key", 0, 0, 1, 60,
	  "It is a quite complex lock, but not impossible\n");
    }
}
