#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    						void create() {
    ::create();                                                                        				set_name("Holy Halo");
    set("id", ({ "holy", "holy halo", "halo" }) );
    set("short", "%^BOLD%^%^WHITE%^Holy Halo%^RESET%^");
    set("long", "%^BOLD%^%^WHITE%^This halo was given to all the angels as a sign of thier goodness and love.%^RESET%^" );
    set_type("helmet");
    set_ac(5);
    set_limbs( ({ "head" }) );
    set_weight(12);
    set_curr_value("gold", 200);
}
int query_auto_load() {
    if (this_player()->query_level() >= 36)
	return 1;
}
