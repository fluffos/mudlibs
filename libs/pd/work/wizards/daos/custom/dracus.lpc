#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_properties( (["no steal" : 1]) );
    set_name("mask");
    set("id", ({"mask", "dracus mask"}) );
    set_short("%^BOLD%^BLACK%^Dracus's Mask%^RESET%^");
    set_long("This is a scary looking mask.");
    set_type("mask");
    set_limbs( ({"head"}) );
}

int query_auto_load() {
    if(this_player()->query_name() == "dracus")
	return 1;
}
