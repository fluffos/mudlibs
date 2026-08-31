#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    
void create() {
    ::create();                                                                        
    set_name("Holy Halo");
    set("id", ({ "blackened", "blackened halo", "halo" }) );
    set("short", "%^BOLD%^%^BLACK%^B%^WHITE%^l%^BLACK%^ackened H%^WHITE%^a%^BLACK%^lo%^RESET%^");
    set("long", "%^BOLD%^%^BLACK%^This halo was once a precious item given to all the angels as a sign of thier goodness and love, but it is now tarnised to black with evil.%^RESET%^" );
    set_type("helmet");
    set_ac(2);
    set_limbs( ({ "head" }) );
    set_weight(12);
    set_curr_value("gold", 100);
}
int query_auto_load() {
    if (this_player()->query_level() >= 20)
	return 1;
}
