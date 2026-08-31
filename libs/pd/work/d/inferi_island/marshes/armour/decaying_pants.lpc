#include <std.h>
#include <amun.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("Decaying Pants");
    set("id", ({ "pants" }) );
    set("short", "%^BOLD%^%^BLACK%^D%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^y%^RESET%^%^ORANGE%^i%^BOLD%^%^BLACK%^ng P%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^nts%^RESET%^");
    set("long", "%^BOLD%^%^BLACK%^Due to the many years of soaking in the marsh, these pants are drenched and in the process of decaying.%^RESET%^");
    set_type("pants");
    set_ac(1);
    set_limbs( ({ "right leg", "left leg"}) );
    set_weight(7);
    set_curr_value("gold", 20);  
}
int query_auto_load() {
    if (this_player()->query_level() >= 10)
	return 1;
}
