// Svenska Clubben! Heja Sverige! Mors grisar {r vi allihoppa!

// Small modifications by Doomdark 19-feb-95.

#include "../DEFS.h"

#include <room_defs.h>
#include <areas.h>
#include <generic_items.h>

inherit TRISTEZA_ROOM_C;
inherit "/basic/misc/emote";

void
create_room()
{
    object bb;
    ::create_room();
    set(ROOM_WD, WD_INDOORS);
    set(PREVENT_TELEPORT);
    set(NO_PK);
    set_short("Svenska Clubben");
    set_long(
      "Du {r i Svenska Clubben. Heja Sverige! NOTE: emote command is available\
 here! Type 'help emote' for more information.");
    set_exits(([ "east" : CITY_DIR + "S13_9" ]));
    set_commands(([
	"emote"	: "emote_cmd",
	"help"	: "help"
      ]));
    add_object(({ GENERIC_BBOARD,
	({ "set_board", 100, 0, "swedish_club_board", 0 }),
      }), 0, 1);
}

status
help(string str)
{
    if (!str || lower_case(str) != "emote") return 0;
    this_player()->tell_me(
      "Command: emote      (Local command - this room only)\n\n\
Arguments: message\n\n\
Generates a neat feeling which you can design yourself.\n\
For example, you (player Foobar), type:\n\
'emote scans the horizon with his bloodshot eyes.'\n\
And the other players in this room see:\n\
'Foobar scans the horizon with his bloodshot eyes.'\n\
Beware of those who emote 'gives you 10000 gold'... :-)");
    return 1;
}
