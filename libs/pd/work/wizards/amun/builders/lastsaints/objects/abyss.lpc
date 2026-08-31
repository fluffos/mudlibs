#include <std.h>
#include <amun.h>
inherit "/std/bag_logic";
void create() {
    ::create();
    set_id( ({"abyss"}) );
    set_name("Abyss");
    set_short("%^BOLD%^%^BLACK%^A%^WHITE%^b%^BLACK%^yss");
    set_weight(15);
    set("long", "%^BOLD%^%^BLACK%^This A%^WHITE%^b%^BLACK%^yss, although huge, is very much portable and can hold quite a few things.");
    set_curr_value("gold", 150);
    set_max_internal_encumbrance(1000);
}
int query_auto_load() {
    if(this_player()->query_guild() == "last saints") return 1;
    return 0;
}
