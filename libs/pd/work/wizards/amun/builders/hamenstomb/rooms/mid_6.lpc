#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long", "%^RESET%^%^YELLOW%^The stairs in this area are not as steep as the ones before, but still make it hard to maneuver. The walls of the pyramid are cracking, showing thier age. Water continues to flow down these cracks as if it is a small waterfall. It is even more active as the next platform approaches. \n");
    set_exits( ([ "southeast" : ROOMS+"hamen_tomb_18", "southwest" : ROOMS+"hamen_tomb_17", "down" : ROOMS+"mid_5", "up" : ROOMS+"mid_7" ]) );
}
