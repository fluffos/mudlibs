#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Temple");
    set("long","%^BOLD%^%^WHITE%^The %^YELLOW%^light %^WHITE%^becomes bright again as the path moves closer to the gate to the west. The laughter and singing grow a little louder along the path. An i%^RESET%^c%^BOLD%^%^WHITE%^e%^RESET%^y %^BOLD%^%^CYAN%^cold%^WHITE%^ breeze moves through the area, giving even the %^GREEN%^v%^RESET%^%^ORANGE%^i%^BOLD%^%^GREEN%^nes %^WHITE%^the chills. Small patches of s%^RESET%^n%^BOLD%^%^WHITE%^ow can be seen ontop of the clouds.%^RESET%^");
    set_items( ([ "light": "%^BOLD%^%^WHITE%^The %^YELLOW%^light %^WHITE%^becomes bright again as the path moves closer to the gate to the west.%^RESET%^", "vines": "%^BOLD%^%^GREEN%^The vines reach up around the clouds offering beautiful scenery.%^RESET%^", "snow" : "%^BOLD%^%^WHITE%^The snow is spread sparactically around the area, leaving the already white clouds a brighter white.%^RESET%^" ]) );
    set_exits( ([ "west" : SKYROOM "lsup_1", "south" : SKYROOM "lsup_3" ]) );
}
