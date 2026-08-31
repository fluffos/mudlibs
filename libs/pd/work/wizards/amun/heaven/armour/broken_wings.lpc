#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    
void create() {
    ::create();                                                                        
    set_name("Broken Wings of Light");
    set("id", ({ "wings", "wing", "wings of light", "of light", "light" }) );
    set("short", "%^BOLD%^%^BLACK%^Br%^WHITE%^o%^BLACK%^k%^WHITE%^e%^BLACK%^n W%^WHITE%^i%^BLACK%^ngs%^RESET%^");
    set("long", "%^BOLD%^%^BLACK%^These wings were once forged for the pure and holy.%^RESET%^");
    set_type("wings");
    set_ac(2);
    set_limbs( ({ "right wing", "left wing" }) );
    set_weight(30);
    set_curr_value("gold", 100);  
}
int query_auto_load() {
    if (this_player()->query_level() >= 25)
	return 1;
}
