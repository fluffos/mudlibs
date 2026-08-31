#include <std.h>
inherit "/std/bag_logic";

void create() {
    ::create();
    set_id( ({"hole", "black hole"}) );
    set_name("Black Hole");
    set_short("%^BOLD%^BLACK%^Black %^RESET%^Hole");
    set_weight(15);
    set("long", "A portable black hole leading to another dimension.");
    set_curr_value("gold", 90);
    set_max_internal_encumbrance(800);
}

int query_auto_load() {
    if(this_player()->query_guild() == "illuminati") return 1;
    return 0;
}
