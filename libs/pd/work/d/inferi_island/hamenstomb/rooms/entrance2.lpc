#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long","%^BOLD%^YELLOW%^This room is unnaturally bright. To the north, a large pyramid can be seen. To the south, the sad marsh reeks of fire and death. There is a slight breeze in the air, that is coming from the gate to the south.%^RESET%^");
    set_items( ([ "pyramid": "%^BOLD%^%^Yellow%^This pyramid belongs to King Hamen." ]) );
    set_exits( ([ "north" : ROOMS+"hamen_square", "south" : ROOMS+"entrance1" ]) );
}
