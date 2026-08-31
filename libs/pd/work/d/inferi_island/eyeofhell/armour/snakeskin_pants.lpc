#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    						void create() {
    ::create();                                                                        				set_name("Snakeskin Pants");
    set("id", ({ "pants" }) );
    set("short", "%^RESET%^%^GREEN%^Sn%^ORANGE%^a%^GREEN%^k%^ORANGE%^e%^GREEN%^sk%^ORANGE%^i%^GREEN%^n P%^ORANGE%^a%^GREEN%^nts%^RESET%^");
    set("long", "%^RESET%^%^GREEN%^These pants were made from the skin of a basilisk.%^RESET%^");
    set_type("pants");
    set_ac(1);
    set_limbs( ({ "right leg", "left leg"}) );
    set_weight(18);
    set_curr_value("gold", 105);  
}
int query_auto_load() {
    if (this_player()->query_level() >= 40)
	return 1;
}
