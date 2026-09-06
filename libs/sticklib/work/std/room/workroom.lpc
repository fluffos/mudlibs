#include <room.h>
#include <generic_rooms.h>
#include <generic_items.h>

void create_room()
{
    set_short("Workroom");
    set_long("This is a standard workroom. You do not usually see any "+
      "of these, except with new coders. Even the desk is empty. There "+
      "is a note on the wall.");
    set_items( ([
	"note" : "This is a workroom of a new coder.",
	"desk" : "It is empty."
      ]) );

    set_exits( ([
	"church" : GENERIC_ROOM_CHURCH,
	"adv"    : GENERIC_ROOM_ADV_GUILD,
	"well"   : GENERIC_ROOM_GALLOWS,
      ]) );

    set_outdoors(WD_INDOORS);
    set_light_level(LT_BRIGHT);

    set(NO_PK);
    set(PREVENT_TELEPORT);

    add_permanent(GENERIC_MAILBOX);
}
