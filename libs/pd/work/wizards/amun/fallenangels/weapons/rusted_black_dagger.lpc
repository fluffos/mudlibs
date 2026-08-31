#include <std.h>
#include <amun.h>
inherit WEAPON;
void create() {
    ::create();
    set_name("Rusted Black Dagger");
    set_id( ({ "dagger", "rusted black dagger", "rusted black", "black dagger", "black", "rusted" }) );
    set_short("%^RESET%^Rusted %^BOLD%^%^BLACK%^Black Dagger%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This dagger is rusted and worthless.%^RESET%^" );
    set_type("knife");
    set_weight(10);
    set_curr_value("gold", 1);
    set_wc(1);
    set("skill level", 2);
}
int query_auto_load() {
    if (this_player()->query_level() >= 2)
	return 1;
}
