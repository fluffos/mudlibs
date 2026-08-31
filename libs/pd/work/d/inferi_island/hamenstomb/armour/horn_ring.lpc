#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    
void create() {
    ::create();                                                                        
    set_name("Horn Ring");
    set("id", ({ "ring" }) );
    set("short", "%^BOLD%^%^BLACK%^Horn Ring%^RESET%^");
    set("long", "%^BOLD%^%^BLACK%^This black band is carved to look like a horn wrapped around your finger.%^RESET%^" );
    set_type("ring");
    set_ac(1);
    set_limbs( ({ "fingers" }) );
    set_weight(5);
    set_curr_value("gold", 100);  
}
int query_auto_load() {
    if (this_player()->query_level() >= 20)
	return 1;
}
