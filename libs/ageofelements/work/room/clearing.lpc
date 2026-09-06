#include <global.h>

inherit LIB_ROOM;

void
create_room()
{
    set_lumens(1);

    set_brief("Clearing");

    set_description(
	"A small clearing. There are trees all around you. "
	"However, the trees are sparse to the north."
      );

    set_exits( ([
	"east": "/room/forest1"
	, "west": "/room/forest2"
	, "north": "/room/plane1"
      ]) );
}
