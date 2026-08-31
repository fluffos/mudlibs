#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^BOLD%^%^BLACK%^A large cave lies to the east, large eyes can be seen peeking out ready to attack anyone who gets too close. Deciding everything looks safe the eyes disappear. The rocks open up to where the marshes can be seen for miles on end. Something can be seen coming out of the marshy waters and ducking behind a shrub.%^RESET%^");
    set_items( ([ "cave": "%^BOLD%^%^BLACK%^Large eyes can be seen peeking out ready to attack anyone who gets too close." ]) );
    set_exits( ([ "west" : MARSHROOM+"marsh_53", "east" : MARSHROOM+"marsh_55" ]) );
    add_pre_exit_function("west", "sp_sap");
    add_pre_exit_function("east", "sp_sap");
}
