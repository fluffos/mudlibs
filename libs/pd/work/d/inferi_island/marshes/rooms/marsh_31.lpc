#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^The mountain pass is riddled with hot black rocks making it hard to move around. The lack of sunlight makes these rocks even more dull than they really are. The sky is made up of black rain clouds for miles. This is not a place of beauty, this is not a place of happiness. This place is cursed.%^RESET%^ ");
    set_items( ([ "rocks": "%^BOLD%^%^BLACK%^These gigantic rocks cover the entire path throughout the entire mountain.", "clouds": "%^BOLD%^%^BLACK%^The black rain clouds reach for miles." ]) );
    set_exits( ([ "east" : MARSHROOM+"marsh_30", "south" : MARSHROOM+"marsh_32" ]) );
    add_pre_exit_function("south", "sp_sap");
    add_pre_exit_function("east", "sp_sap");
}
