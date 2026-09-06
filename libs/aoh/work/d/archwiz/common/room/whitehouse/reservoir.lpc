inherit "std/room";

#include <rooms.h>
#include "path.h"

create() {
	::create();
	SetIntShort("Empty Reservoir");
	SetIntLong(
"You are on what used to be a large lake, but which is now a large "
"mud pile. There are ``shores'' to the north and south.\n");
	SetIndoors(1);
	SetBright(-10);
	AddDetail(({"empty reservoir","reservoir"}),#'IntLong);
	AddDetail(({"shore","shores"}),
"Maybe you should head back there before the water returns.\n");
	AddDetail(({"large mud pile","mud pile","pile","mud",
	   "large pile","large mud"}),
"It is still very wet and you are sinking in quite deep.\n");
	AddDetail(({"lake","large lake"}),
"It is gone now that the dam is open. Only a small stream of water is "
"trickling through the mud.\n");
	AddExit("north","./reservoir_north");
	AddExit("south","./reservoir_south");
        AddItem(OBJ("whchest"),REFRESH_REMOVE);
	reset();
}
