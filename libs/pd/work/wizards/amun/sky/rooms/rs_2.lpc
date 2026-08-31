#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Temple");
    set("long","%^BOLD%^%^WHITE%^The clouds lay softly along the roads path, allowing passerbys to comfortably walk towards their destination. Facing north, there is a sign on the side of a building that reads '%^YELLOW%^The Sky Temple Weapons%^WHITE%^'. To the south, there is a small path that offers anyone a seat after a long day. Birds fly around, taking in a beautiful day.%^RESET%^");
    set_items( ([ "clouds": "%^BOLD%^%^WHITE%^The clouds lay softly along the roads path. They offer a cushion for the barefooted.%^RESET%^", "sign": "%^BOLD%^%^WHITE%^The sign reads '%^YELLOW%^The Sky Temple Weapons%^WHITE%^'.%^RESET%^", "birds": "%^BOLD%^%^BLUE%^Birds %^GREEN%^of %^MAGENTA%^all %^YELLOW%^colors %^RESET%^%^MAGENTA%^fly %^BOLD%^%^RED%^around%^WHITE%^.%^RESET%^"]) );
    set_exits( ([ "west" : SKYROOM "rs_1", "east" : SKYROOM "rs_3", "north" : SKYROOM "weapon_shop", "south" : SKYROOM "rs_8" ]) );
}
