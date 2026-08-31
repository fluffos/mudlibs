#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    						void create() {
    ::create();                                                                        				set_name("Snakeskin Shirt");
    set("id", ({ "shirt" }) );
    set("short", "%^RESET%^%^GREEN%^Sn%^ORANGE%^a%^GREEN%^k%^ORANGE%^e%^GREEN%^sk%^ORANGE%^i%^GREEN%^n Sh%^ORANGE%^i%^GREEN%^rt%^RESET%^");
    set("long", "%^RESET%^%^GREEN%^This shirt was made from the skin of a basilisk.%^RESET%^" );
    set_type("shirt");
    set_ac(1);
    set_limbs( ({ "right arm", "left arm", "torso" }) );
    set_weight(15);
    set_curr_value("gold", 105);  
}                                                                                                                        int query_auto_load() {
    if (this_player()->query_level() >= 40)
	return 1;
}
