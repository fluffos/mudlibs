#include <std.h>
#include <amun.h>
inherit VAULT;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long","%^BOLD%^YELLOW%^Things get bright as you enter this room.  You look up and see a huge Pyramid infront of you.  The entrance is just ahead.\n");
    set_items( ([ "pyramid": "%^BOLD%^%^YELLOW%^This pyramid belongs to King Hamen." ]) );
    set_exits( ([ "north" : ROOMS+"entrance2", "south" : ROOMS+"marsh_end" ]) );
}
