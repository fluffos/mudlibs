#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Temple");
    set("long","%^BOLD%^%^WHITE%^More and more, the Trail leads moves uphill, allowing the %^CYAN%^air %^WHITE%^to feel more fantastic. Facing south, there is a sign on the side of a building that reads '%^BOLD%^%^WHITE%^The C%^RESET%^a%^BOLD%^%^WHITE%^th%^RESET%^e%^BOLD%^%^WHITE%^dr%^RESET%^a%^BOLD%^%^WHITE%^l Restaurant'. To the north, strange %^GREEN%^li%^CYAN%^gh%^MAGENTA%^ts %^WHITE%^can be seen flashing. A slight %^CYAN%^breeze %^WHITE%^flows along the trail.%^RESET%^");
    set_items( ([ "clouds": "%^BOLD%^%^WHITE%^The clouds lay softly along the roads path. They offer a cushion for the barefooted.%^RESET%^", "sign": "%^BOLD%^%^WHITE%^The sign reads '%^BOLD%^%^WHITE%^The C%^RESET%^a%^BOLD%^%^WHITE%^th%^RESET%^e%^BOLD%^%^WHITE%^dr%^RESET%^a%^BOLD%^%^WHITE%^l Restaurant'.%^RESET%^", "lights": "%^BOLD%^%^WHITE%^To the north, strange %^GREEN%^li%^CYAN%^gh%^MAGENTA%^ts %^WHITE%^can be seen flashing.%^RESET%^"]) );
    set_exits( ([ "east" : SKYROOM "ls_4", "west" : SKYROOM "ls_6", "north" : SKYROOM "mage_hall1", "south" : SKYROOM "food_shop" ]) );
}
