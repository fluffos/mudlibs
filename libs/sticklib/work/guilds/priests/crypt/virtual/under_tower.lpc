#include <room.h>
#include <guild.h>
#include "../DEFS.h"

string my_long() {
    return sprintf("You are in a small dusty room. The walls are build from \
stones, and here and there water drips from cracks between them. A ladder \
attached to the wall leads up to a hatch in the ceiling, which is %s. A tunnel \
leads to the southwest.", PRIEST_TOWER->query_hatch_open() ? "open" : "closed");
}


void create_room()
{
    set_light_level(LT_DARKNESS);
    set(ROOM_WD, WD_INDOORS);
    set_short("An old tunnel");
    set_long(#'my_long);
    set_items(([
	"hatch" : "It is a wooden hatch.",
	"ladder" : "It is an iron ladder attached to the stone wall.",
	({"wall", "walls"}): "They are made from large stones. Not very cosy \
unless you are a dwarf.",
	({"crack", "cracks"}): "Water drips from them on the floor, and dissapears \
somewhere between the floor stones.",
      ]));
    set_exits(([
	"southwest" : ROOM_DIR "passage2",
      ]));
}

status open_cmd(string what) {
    if(what != "hatch") return 0;
    if(PRIEST_TOWER->query_hatch_open())
	return notify_fail("But it is already open!\n"),0;
    PRIEST_TOWER->open_hatch(1);
    return 1;
}

status close_cmd(string what) {
    if(what != "hatch") return 0;
    if(!PRIEST_TOWER->query_hatch_open())
	return notify_fail("But it is already closed!\n"),0;
    PRIEST_TOWER->close_hatch(0);
    return 1;
}
