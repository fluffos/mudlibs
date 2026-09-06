#include <global.h>

inherit LIB_ROOM;

void
create_room()
{
    set_lumens(1);

    set_brief("The inner room of Adventurers Guild");

    set_description(
	"This is the inner room of adventures guild. If you want to discuss "
	"LPC, then move to the room south from here. Only wizards can access "
	"this room."
      );

    set_exits( ([
	"north": "/room/adv_guild"
	, "south": "/room/adv_inner2"
      ]) );

    add_permanent_object("/obj/wiz_bull_board");
}
