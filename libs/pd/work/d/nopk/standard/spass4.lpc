#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 ::create();
    set_property("light", 2);
    set_property("no castle", 1);
    set("short", "Southern wall along the Daroq Mountains Pass");
    set("long",
        "The ledge overlooks the actual pass, far below. Several "
        "loose rocks make this thin ledge a fairly dangerous place "
        "to be. A small cave entrance rests in the mountain walls here.");
    set_exits(([ "west" : ROOMS"spass5",
                 "cave" : "/d/nopk/trollcaves/room/cave1",
                 "east" : ROOMS"spass3" ]));
}
