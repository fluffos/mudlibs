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
	"east": "/room/clearing"
	, "west": "/room/slope"
      ]) );

    add_transient_object( ({ "/obj/monster"
	, ({ "set_name", "troll" })
	, ({ "set_level", 9 })
	, ({ "set_hp", 100 })
	, ({ "set_wc", 12 })
	, ({ "set_al", -60 })
	, ({ "set_short", "A troll" })
	, ({ "set_long", "It is a nasty troll that looks very aggressive." })
	, ({ "set_aggressive", 1 })
	, ({ "set_spell_mess1", "The troll says: You'll get no treasure from me!" })
	, ({ "set_spell_mess2", "The troll says: Your mother smelt of elderberries!" })
	, ({ "set_chance", 20 })
	, ({ "set_money", random(500) })
      }) );
}
