#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Temple");
    set("long","%^RESET%^%^ORANGE%^Dimmer %^BOLD%^%^WHITE%^and %^RESET%^%^ORANGE%^dimmer %^BOLD%^%^WHITE%^the light becomes as the clouds grow more fluffy, they look as if they are beginning to form something. %^GREEN%^Green v%^RESET%^%^ORANGE%^i%^BOLD%^%^GREEN%^nes %^WHITE%^begin to reach up from under the clouds and wrap themselves around the forming clouds. %^RESET%^%^ORANGE%^L%^GREEN%^e%^ORANGE%^a%^GREEN%^v%^ORANGE%^e%^GREEN%^s %^BOLD%^%^WHITE%^can be seen blowing through from the southeast.%^RESET%^");
    set_items( ([ "clouds": "%^BOLD%^%^WHITE%^The clouds look as if they are beginning to form an arch.%^RESET%^", "vines": "%^BOLD%^%^GREEN%^The vines reach up around the clouds offering beautiful scenery.%^RESET%^", "leaves" : "%^RESET%^%^ORANGE%^L%^GREEN%^e%^ORANGE%^a%^GREEN%^v%^ORANGE%^e%^GREEN%^s %^BOLD%^%^WHITE%^can be seen blowing through from the east.%^RESET%^" ]) );
    set_exits( ([ "south" : SKYROOM "rsup_8", "north" : SKYROOM "rsup_6" ]) );
}
