#include <std.h>
#include <amun.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("Shirt of Tattered Rags");
    set("id", ({ "shirt", "rags" }) );
    set("short", "%^BOLD%^%^BLACK%^Shirt of %^RESET%^%^ORANGE%^T%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^tt%^BOLD%^%^BLACK%^e%^RESET%^ORANGE%^r%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^d R%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^gs%^RESET%^");
    set("long", "%^BOLD%^%^BLACK%^This is an old decayed shirt made from %^RESET%^%^ORANGE%^t%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^tt%^BOLD%^%^BLACK%^e%^RESET%^ORANGE%^r%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^d r%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^gs.%^RESET%^" );
    set_type("shirt");
    set_ac(2);
    set_limbs( ({ "torso", "left arm", "right arm" }) );
    set_weight(3);
    set_curr_value("gold", 10);  
}
int query_auto_load() {
    if (this_player()->query_level() >= 10)
	return 1;
}
