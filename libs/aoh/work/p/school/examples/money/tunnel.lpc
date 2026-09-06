/*
* Tunnel through the examples of Finance
* by Thragor, 12apr94
*/

#include <config.h>
#include <rooms.h>

inherit "/std/room";

create()
{
 ::create();

 SetIndoors(1);
 SetBright(MAX_SUNBRIGHT/2);
 SetIntShort("a tunnel");
 SetIntLong(
"This is a tunnel through the examples of the Finance Department.\n"
"To the west is one of the most expensive shops in the mud.\n");

 AddExit("west","./exashop");
 AddExit("up","../office");

 AddItem("/d/archwiz/common/finance/exm/rosie",REFRESH_REMOVE);
}
