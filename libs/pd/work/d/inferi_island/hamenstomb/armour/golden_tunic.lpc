#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    
void create() {
    ::create();                                                                        
    set_name("Golden Tunic");
    set("id", ({ "tunic" }) );
    set("short", "%^BOLD%^%^YELLOW%^Golden %^WHITE%^Tunic%^RESET%^");
    set("long", "%^BOLD%^%^WHITE%^Light and breezy is this tunic. It is very rare and offers good protection to any who wears it.%^RESET%^" );
    set_type("tunic");
    set_ac(3);
    set_limbs( ({ "right leg", "left leg" }) );
    set_weight(30);
    set_curr_value("gold", 130); 
    set_property("magic item", ({ "illuminate" }) );
    set_property("magic item", ({ "command" }) );
}
int query_auto_load() {
    if (this_player()->query_level() >= 45)
	return 1;
}
