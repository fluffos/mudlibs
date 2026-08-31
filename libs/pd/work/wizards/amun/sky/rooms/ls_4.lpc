#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Temple");
    set("long","%^BOLD%^%^WHITE%^The more west the Trail leads, the more warm and crisp the %^CYAN%^air %^WHITE%^feels. The clouds seem to be gathering, making the road move uphill. Facing north, there is a sign on the side of a building that reads '%^BOLD%^%^WHITE%^The C%^RESET%^a%^BOLD%^%^WHITE%^th%^RESET%^e%^BOLD%^%^WHITE%^dr%^RESET%^a%^BOLD%^%^WHITE%^l Bakery'. To the south, the sound of cheering and screaming can be heard.%^RESET%^");
    set_items( ([ "clouds": "%^BOLD%^%^WHITE%^The clouds lay softly along the roads path. They offer a cushion for the barefooted.%^RESET%^", "sign": "%^BOLD%^%^WHITE%^The sign reads '%^BOLD%^%^WHITE%^The C%^RESET%^a%^BOLD%^%^WHITE%^th%^RESET%^e%^BOLD%^%^WHITE%^dr%^RESET%^a%^BOLD%^%^WHITE%^l Bakery'.%^RESET%^"]) );
    set_exits( ([ "east" : SKYROOM "ls_3", "west" : SKYROOM "ls_5", "north" : SKYROOM "pastry_shop", "south" : SKYROOM "fighter_hall1" ]) );
}
