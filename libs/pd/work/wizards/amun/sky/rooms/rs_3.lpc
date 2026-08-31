#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Temple");
    set("long","%^BOLD%^%^WHITE%^The clouds gather slightly the more east the path leads on Belief Trail. Facing south, there is a sign on the side of a building that reads '%^YELLOW%^Sky Temple Healing Shop%^WHITE%^'. To the north, %^CYAN%^lights %^WHITE%^can be seen flickering under the small crack at the bottom of the door. A few %^GREEN%^pl%^RESET%^%^ORANGE%^a%^BOLD%^%^GREEN%^nts %^WHITE%^can be seen magically growing through a tuft of clouds.%^RESET%^");
    set_items( ([ "clouds": "%^BOLD%^%^WHITE%^The clouds lay softly along the roads path. They offer a cushion for the barefooted.%^RESET%^", "sign": "%^BOLD%^%^WHITE%^The sign reads '%^YELLOW%^Sky Temple Healing Shop%^WHITE%^'.%^RESET%^", "plants": "%^BOLD%^%^GREEN%^The plants seem to be growing magically through the clouds.%^RESET%^"]) );
    set_exits( ([ "west" : SKYROOM "rs_2", "east" : SKYROOM "rs_4", "north" : SKYROOM "clergy_hall1", "south" : SKYROOM "oil_shop" ]) );
}
