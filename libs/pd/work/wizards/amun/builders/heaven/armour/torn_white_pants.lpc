#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    
void create() {
    ::create();                                                                        
    set_name("Torn White Pants");
    set("id", ({ "pants", "pant", "torn white pants", "torn white pant" }) );
    set("short", "T%^ORANGE%^o%^RESET%^rn White P%^ORANGE%^a%^RESET%^nts");
    set("long", "These pants were once made out of pure holiness and love.%^RESET%^");
    set_type("pants");
    set_ac(1);
    set_limbs( ({ "right leg", "left leg"}) );
    set_weight(20);
    set_curr_value("gold", 100);  
}
int query_auto_load() {
    if (this_player()->query_level() >= 25)
	return 1;
}
