#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    						void create() {
    ::create();                                                                        				set_name("Recluse Bracers");
    set("id", ({ "bracers" }) );
    set("short", "%^RESET%^%^ORANGE%^Recluse Bracers%^RESET%^");
    set("long", "%^RESET%^%^ORANGE%^These bracers were made for raknids to protect thier legs.%^RESET%^" );
    set_type("bracers");
    set_ac(4);
    set_limbs( ({ "right rear leg", "left rear leg", "left foreleg", "right foreleg" }) );
    set_weight(15);
    set_curr_value("gold", 100);
}
int query_auto_load() {
    if (this_player()->query_level() >= 36)
	return 1;
}
