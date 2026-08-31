#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Temple");
    set("long","%^RESET%^%^ORANGE%^Dimmer %^BOLD%^%^WHITE%^and %^RESET%^%^ORANGE%^dimmer %^BOLD%^%^WHITE%^the light becomes as the clouds grow more fluffy, they look as if they are beginning to form something. %^GREEN%^Green v%^RESET%^%^ORANGE%^i%^BOLD%^%^GREEN%^nes %^WHITE%^begin to reach up from under the clouds and wrap themselves around the forming clouds. The sound of singing and cheerful laughter can be heard coming from the northwest. %^YELLOW%^Light %^WHITE%^can be seen from the north.%^RESET%^");
    set_items( ([ "clouds": "%^BOLD%^%^WHITE%^The clouds look as if they are beginning to form an arch.%^RESET%^", "vines": "%^BOLD%^%^GREEN%^The vines reach up around the clouds offering beautiful scenery.%^RESET%^" ]) );
    set_exits( ([ "north" : SKYROOM "lsup_2", "south" : SKYROOM "lsup_4" ]) );
}
