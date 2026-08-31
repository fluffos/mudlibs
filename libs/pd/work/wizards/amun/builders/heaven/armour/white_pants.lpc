#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    						void create() {
    ::create();                                                                        				set_name("White Leather Pants");
    set("id", ({ "pants", "pant", "white leather pants", "white leather pant" }) );
    set("short", "%^BOLD%^%^WHITE%^White Leather Pants%^RESET%^");
    set("long", "%^BOLD%^%^WHITE%^These pants were made out of pure holiness, love and of course leather.%^RESET%^");
    set_type("pants");
    set_ac(2);
    set_limbs( ({ "right leg", "left leg"}) );
    set_weight(20);
    set_curr_value("gold", 200);  
}
int query_auto_load() {
    if (this_player()->query_level() >= 40)
	return 1;
}
