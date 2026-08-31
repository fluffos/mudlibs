#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^A recent rockslide has laid a small hill of rocks barring the way. The top of the small hill provides an excellent view of the surrounding areas.  The view is far from spectacular, nothing but dull gray rock as far as the eye can see.  The path remains clear on the otherside of the hill heading deeper into the mountain.%^RESET%^");
    set_exits( ([ "east" : MARSHROOM+"marsh_42", "south" : MARSHROOM+"marsh_44" ]) );
    add_pre_exit_function("south", "sp_sap");
    add_pre_exit_function("east", "sp_sap");
}
