#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    
void create() {
    ::create();                                                                        
    set_name("Black Leather Shirt");
    set("id", ({ "shirt" }) );
    set("short", "%^BOLD%^%^BLACK%^Black Leather Shirt%^RESET%^");
    set("long", "%^BOLD%^%^BLACK%^This shirt is made for those whom walk in the night, those who wish to be concealed by sh%^WHITE%^a%^BLACK%^d%^WHITE%^o%^BLACK%^ws.  The leather is unusually %^WHITE%^light%^BLACK%^, but is strong and hard to penetrate.%^RESET%^" );
    set_type("shirt");
    set_ac(1);
    set_limbs( ({ "right arm", "left arm", "torso" }) );
    set_weight(15);
    set_curr_value("gold", 25);  
}
int query_auto_load() {
    if (this_player()->query_level() >= 40)
	return 1;
}
