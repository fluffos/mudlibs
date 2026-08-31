#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Temple");
    set("long","%^BOLD%^%^WHITE%^The clouds begin to shift with the wind, causing the trail to move uphill. Magically placed %^GREEN%^p%^RESET%^%^ORANGE%^l%^BOLD%^%^GREEN%^ants %^WHITE%^grow on both sides of the trail, allowing a %^MAGENTA%^sweet smell %^WHITE%^to encompass the area. The %^YELLOW%^lig%^RESET%^%^ORANGE%^ht %^BOLD%^%^WHITE%^in the room becomes %^RESET%^%^ORANGE%^dimmer %^BOLD%^%^WHITE%^due to the abundance of clouds. A few angels move north heading towards something.%^RESET%^");
    set_items( ([ "clouds": "%^BOLD%^%^WHITE%^The clouds begin to shift with the wind, causing the trail to move uphill.%^RESET%^", "plants": "%^BOLD%^%^RED%^Roses%^WHITE%^, %^BLUE%^violets%^WHITE%^, %^MAGENTA%^carnations %^WHITE%^and many other %^GREEN%^fl%^YELLOW%^ow%^MAGENTA%^er%^BLUE%^s %^WHITE%^and %^GREEN%^p%^RESET%^%^ORANGE%^l%^GREEN%^ants %^WHITE%^grow in this area.%^RESET%^" ]) );
    set_exits( ([ "north" : SKYROOM "lsup_3", "south" : SKYROOM "lsup_5" ]) );
}
