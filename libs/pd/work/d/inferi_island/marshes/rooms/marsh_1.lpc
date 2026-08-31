#include <std.h>
#include <amun.h>
inherit ROOM;
object ob;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^The mountain pass is riddled with hot black rocks making it hard to move around. The lack of sunlight makes these rocks even more dull than they really are. The sky is made up of black rain clouds stretching for miles. This is not a place of beauty, this is not a place of happiness, this place is cursed.%^RESET%^ ");
    set_items( ([ "rocks": "%^BOLD%^%^BLACK%^These gigantic rocks cover the entire path throughout the entire mountain.%^RESET%^", "clouds": "%^BOLD%^%^BLACK%^The black rain clouds reach for miles.%^RESET%^" ]) );
    set_exits( ([ "north" : MARSHROOM+"marsh_17", "west": MARSHROOM+"marsh_2", "southeast": MARSHROOM+"marsh_square" ]) );
}
