#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Temple");
    set("long","%^BOLD%^%^WHITE%^The more east the Trail leads, the more warm and crisp the %^CYAN%^air %^WHITE%^feels. The clouds seem to be gathering, making the road move uphill. Facing north, there is a sign on the side of a building that reads '%^YELLOW%^Sky Temple Armoury%^WHITE%^'. To the south, dark figures can barely be seen lurking in the shadows.%^RESET%^");
    set_items( ([ "clouds": "%^BOLD%^%^WHITE%^The clouds lay softly along the roads path. They offer a cushion for the barefooted.%^RESET%^", "sign": "%^BOLD%^%^WHITE%^The sign reads '%^YELLOW%^Sky Temple Armoury%^WHITE%^'.%^RESET%^"]) );
    set_exits( ([ "west" : SKYROOM "rs_3", "east" : SKYROOM "rs_5", "north" : SKYROOM "armour_shop", "south" : SKYROOM "rogue_hall1" ]) );
}
