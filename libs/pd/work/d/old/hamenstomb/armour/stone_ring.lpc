#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    
void create() {
    ::create();                                                                        
    set_name("stone Ring");
    set("id", ({ "ring" }) );
    set("short", "%^BOLD%^%^WHITE%^Sto%^RESET%^%^WHITE%^ne R%^BOLD%^%^WHITE%^ing");
    set("long", "%^BOLD%^%^WHITE%^This ring was carved into a perfect band that seems to fit anyone who holds it." );
    set_type("ring");
    set_ac(2);
    set_limbs( ({ "fingers" }) );
    set_weight(10);
    set_curr_value("gold", 100);
}
int query_auto_load() {
    if (this_player()->query_level() >= 25)
	return 1;
}
