#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Temple");
    set("long","%^RESET%^%^ORANGE%^Dimmer %^BOLD%^%^WHITE%^and %^RESET%^%^ORANGE%^dimmer %^BOLD%^%^WHITE%^the light becomes as the clouds grow more fluffy, they look as if they are beginning to form something. %^RESET%^%^GREEN%^Green v%^ORANGE%^i%^GREEN%^nes %^BOLD%^%^WHITE%^begin to reach up from under the clouds and wrap themselves around the forming clouds. The sound of screaming and %^RESET%^%^MAGENTA%^sorrowful song %^BOLD%^%^WHITE%^filters down along the path as if there is great agony around. %^YELLOW%^Light %^WHITE%^can be seen from the south.%^RESET%^");
    set_items( ([ "clouds": "%^BOLD%^%^WHITE%^The clouds look as if they are beginning to form an arch.%^RESET%^", "vines": "%^RESET%^%^GREEN%^The vines reach up around the clouds.%^RESET%^" ]) );
    set_exits( ([ "south" : SKYROOM "rsup_4", "north" : SKYROOM "rsup_2" ]) );
}
