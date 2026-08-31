#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    
void create() {
    ::create();                                                                        
    set_name("Black Leather Pants");
    set("id", ({ "pants" }) );
    set("short", "%^BOLD%^%^BLACK%^Black Leather Pants");
    set("long", "%^BOLD%^%^BLACK%^Strong and built for speed, these pants are perfect for those who wish to %^RESET%^%^RED%^hunt %^BOLD%^%^BLACK%^in the sh%^WHITE%^a%^BLACK%^d%^WHITE%^o%^BLACK%^ws.");
    set_type("pants");
    set_ac(1);
    set_limbs( ({ "right leg", "left leg"}) );
    set_weight(15);
    set_curr_value("gold", 45);  
}
int query_auto_load() {
    if (this_player()->query_level() >= 40)
	return 1;
}
