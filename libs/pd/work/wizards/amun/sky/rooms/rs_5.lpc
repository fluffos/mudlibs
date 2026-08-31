#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Temple");
    set("long","%^BOLD%^%^WHITE%^More and more, the Trail leads moves uphill, allowing the %^CYAN%^air %^WHITE%^to feel more fantastic. Facing south, there is a sign on the side of a building that reads '%^YELLOW%^Sky Temple Supply%^WHITE%^'. To the north, drums can be heard and an ice chest can be seen while strange people wander around. A slight %^CYAN%^breeze %^WHITE%^flows along the trail.%^RESET%^");
    set_items( ([ "clouds": "%^BOLD%^%^WHITE%^The clouds lay softly along the roads path. They offer a cushion for the barefooted.%^RESET%^", "sign": "%^BOLD%^%^WHITE%^The sign reads '%^YELLOW%^Sky Temple Supply%^WHITE%^'.%^RESET%^"]) );
    set_exits( ([ "west" : SKYROOM "rs_4", "east" : SKYROOM "rs_6", "north" : SKYROOM "wanderer_hall1", "south" : SKYROOM "misc_shop" ]) );
}
