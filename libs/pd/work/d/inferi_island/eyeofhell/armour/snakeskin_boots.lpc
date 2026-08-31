#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    
void create() {
    ::create();                                                                        
    set_name("Snakeskin Boots");
    set("id", ({ "boots" }) );
    set("short", 
      "%^RESET%^%^GREEN%^Sn%^ORANGE%^a%^GREEN%^k%^ORANGE%^e%^GREEN%^sk%^ORANGE%^i%^GREEN%^n B%^ORANGE%^oo%^GREEN%^ts%^RESET%^");
    set("long", "%^RESET%^%^GREEN%^These boots were made from the skin of a basilisk.%^RESET%^" );
    set_type("boots");
    set_ac(3);
    set_limbs( ({ "right foot", "left foot" }) );
    set_weight(15);
    set_curr_value("gold", 130);
}
int query_auto_load() {
    if (this_player()->query_level() >= 40)
	return 1;
}
