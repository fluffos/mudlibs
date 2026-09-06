#include <door_defs.h>
#include <bboard_defs.h>
#include <generic_items.h>
#include "priest_room.h"

int valid_board_access(object me);

void create_room() {
    set_short("The Cathedral's bell tower.");
    set_long("The council room. There's a large plaque on the wall.");
    set_items(([
	"plaque" : "There's this text written with large letters on it:\n\
*** UNDER CONSTRUCTION ***",
      ]));

    set(ROOM_WD, WD_INDOORS);
    set(PREVENT_TELEPORT);
    set_light_level(LT_LIGHTS);
    set(ROOM_GUILD);
    set(ROOM_WD,WD_INDOORS);
    set(NO_CLEANUP);

    /* Bulletin board */
    add_object(({ GENERIC_BBOARD,
	({ "set_board", 100, ([
	    BB_WRITE_CLOSURE : #'valid_board_access,
	    BB_READ_CLOSURE : #'valid_board_access,
	  ]), "priest_guild_officer", 0 }),
      }), 0, 1);

    add_exit("down", PRIEST_ROOM_DIR "2tower");
}

status read_cmd(string what) {
    string str;
    str = query_long(what);
    if(!str) return 0;
    this_player()->tell_me(str);
    return 1;
}

int valid_board_access(object me)
{
    if(me->query_coder_level())
	return 1;
    if(me->query_guild()  !=  GN_PRIEST  ||
      me->query_guild_object()->query_rank()<2)
	return 0;
    return 1;
}
