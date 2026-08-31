#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long", "%^RESET%^%^YELLOW%^This room was made for the people who made this pyramid to be able to reach the top quickly, it was also the direct way down incase of a cave in. The walls are lined with ropes and there is water dripping down the sides of the walls. There are torches halfway up the wall that flicker slightly from the shafts above.\n");
    set_exits( ([ "southwest" : ROOMS+"mid_3", "southeast" : ROOMS+"mid_4", "up" : ROOMS+"mid_6", "down" : ROOMS+"middle_1" ]) );
}
