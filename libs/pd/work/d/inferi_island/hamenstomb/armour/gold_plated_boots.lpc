#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    
void create() {
    ::create();                                                                        
    set_name("Gold Plated Boots");
    set("id", ({ "boots" }) );
    set("short", "%^BOLD%^%^YELLOW%^Gold Plated Boots%^RESET%^");
    set("long", "%^BOLD%^%^YELLOW%^Made by the Egyptians, these boots offer little room but tons of protection.%^RESET%^" );
    set_type("boots");
    set_ac(6);
    set_limbs( ({ "right foot", "left foot" }) );
    set_weight(30);
    set_curr_value("gold", 250);
}
int query_auto_load() {
    if (this_player()->query_level() >= 46)
	return 1;
}
