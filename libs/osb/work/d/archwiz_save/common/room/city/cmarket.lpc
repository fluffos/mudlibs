inherit "std/room";
#include "path.h"
#include <rooms.h>;

create() {
 ::create();
 SetIntShort("Inside the carpet-shop");
 SetIntLong(
 "This is the shop of the famous merchant Ali Bubu. Huge piles of carpets\n\
are lying everywhere.\n");
 SetIndoors(1);
 AddDetail(({"shop","room","carpet-shop"}),QueryIntLong());
 AddDetail(({"carpets","pile of carpets","huge pile","piles of carpets",
 "huge piles","huge piles of carpets","huge pile of carpets"}),
"They cover the whole ground. If you are lucky, a flying carpet may be here.\n");
 AddDetail(({"floor","ground"}),
"The whole ground is covered by carpets.\n");
 AddExit("east","./yard");
 // Changed to REFRESH_REMOVE Softbyte,AWofMagic
// Commented out the file, as the carpet doesn't exist
// Sonic, 18-May-1997
// AddItem(CARPET,REFRESH_REMOVE);
}
