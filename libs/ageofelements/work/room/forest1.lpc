#include <global.h>

inherit LIB_ROOM;

void
create_room()
{
    set_lumens(1);

    set_brief("In a forest");

    set_description(
	"You are in a big forest."
      );

    set_exits( ([
	"east": "/room/wild1"
	, "west": "/room/clearing"
      ]) );

    add_transient_object( ({ "/obj/armour"
	, ({ "set_name", "leather jacket" })
	, ({ "set_short", "A leather jacket" })
	, ({ "set_alias", "jacket" })
	, ({ "set_long", "A worn but sturdy leather jacket. \
On the back is a lot of rivets making the pattern of a star." })
	, ({ "set_value", 50 })
	, ({ "set_weight", 2 })
	, ({ "set_ac", 2 })
	, ({ "set_type", "armour" })
      }) );
}
