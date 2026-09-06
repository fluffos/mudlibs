#include "path.h"
#include <rooms.h>
inherit "/std/room";

create() {
    ::create();
    SetIntShort(
"You are in the main hall of Firestone's castle.");
    SetIntLong(
"This is the main hall of Firestone's castle. All around you see piles of "
"tires. In the middle of the room stands a drink dispenser.\n");
    SetIndoors(1);
    AddDetail(({"hall","main hall"}),QueryIntLong());
    AddReadMsg("note",
"This is a note from the owner of the dispenser, "
"Flathead Enterprises(c). You read:\n"
"  Vandalism is a crime. We will not be "
"liable for any injuries, physical or mental, "
"which occur to you as a result of kicking "
"this dispenser.\n"
"      - The Management at Flathead Enterprise(C)\n");
    AddDetail("note","Read it!\n");
    AddDetail(({"tires","tire"}),
"One tire is very large and seems to be a tire for a spaceship.\n\
The other tires are small car tires.\n");
    AddDetail("piles","Just look at all those tires!\n");
    AddDetail("dispenser","There is a small note on the dispenser.\n");
    AddExit("west",CITY("fields"));
    AddExit("east","./storage");
    AddItem(FIRESTONE("cat"),REFRESH_REMOVE);
    AddItem(FIRESTONE("disp"),REFRESH_HOME);
}
