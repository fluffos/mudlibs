#include <std.h>
#include "../defs.h"
inherit INH+"tunnel2";

void create() {
    ::create();
    set_long(::query_long()+" The ceiling features a large hole.\n");
    set_exits(([
      "southeast" : TUNNEL"tunnel19",
      "northwest" : TUNNEL"tunnel21",
        ]));
    set_climb_exits(([
        "climb" : ({"/d/player_houses/innaeli/rooms/tunnel1", 20, 6, 100}),
        ]));
}

