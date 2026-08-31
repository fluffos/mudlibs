#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    						void create() {
    ::create();                                                                        				set_name("Decaying Pants");
    set("id", ({ "pants" }) );
    set("short", "%^BOLD%^%^RED%^Bloo%^RESET%^%^RED%^dy P%^BOLD%^%^RED%^ants");
    set("long", "%^BOLD%^%^RED%^These bloo%^RESET%^%^RED%^dy p%^BOLD%^%^RED%^ants are heavy with thick blood.");
    set_type("pants");
    set_ac(2);
    set_limbs( ({ "right leg", "left leg"}) );
    set_weight(3);
    set_curr_value("gold", 20);  
}
int query_auto_load() {
    if (this_player()->query_level() >= 10)
	return 1;
}
