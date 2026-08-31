#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Temple");
    set("long","%^BOLD%^%^WHITE%^The clouds lay softly along the roads path, allowing passerbys to comfortably walk towards their destination. Facing north, there is a sign on the side of a building that reads 'The C%^RESET%^a%^BOLD%^%^WHITE%^th%^RESET%^e%^BOLD%^%^WHITE%^dr%^RESET%^a%^BOLD%^%^WHITE%^l Vineyard'. To the south, there is a small path that offers anyone a seat after a long day. Birds fly around, taking in a beautiful day.%^RESET%^");
    set_items( ([ "clouds": "%^BOLD%^%^WHITE%^The clouds lay softly along the roads path. They offer a cushion for the barefooted.%^RESET%^", "sign": "%^BOLD%^%^WHITE%^The sign reads 'The C%^RESET%^a%^BOLD%^%^WHITE%^th%^RESET%^e%^BOLD%^%^WHITE%^dr%^RESET%^a%^BOLD%^%^WHITE%^l Vineyard'.%^RESET%^", "birds": "%^BOLD%^%^BLUE%^Birds %^GREEN%^of %^MAGENTA%^all %^YELLOW%^colors %^RESET%^%^MAGENTA%^fly %^BOLD%^%^RED%^around%^WHITE%^.%^RESET%^"]) );
    set_exits( ([ "east" : SKYROOM "ls_1", "west" : SKYROOM "ls_3", "north" : SKYROOM "alcohol_shop", "south" : SKYROOM "ls_8" ]) );
}
