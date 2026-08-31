#include <std.h>

inherit VAULT;

void create() {
    ::create();

    set("short", "Room");
    set("long", "Sample 1\nIt's time to begin your journey, young one. There is a door to the north. you must <open door> before you can continue.");

    set_exits(([ "north" : "/wizards/pyro/doors/sample2" ]));
    cover_exit_with_door("north", "pyrodoor1");
}
