#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_name("sash");
    set("id", ({"sash, forbidden sash"}) );
    set_short("%^BOLD%^BLUE%^Fo%^RESET%^BLUE%^rb%^RESET%^id%^BOLD%^d%^"
      "%^RESET%^en %^BLUE%^Sa%^BOLD%^sh%^RESET%^");
    set_long("This is a sash made for Evo.");
    set_type("sash");
    set_limbs( ({"torso"}) );
}

int query_auto_load() {
    if(this_player()->query_name() == "evo")
	return 1;
}
