#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    
void create() {
    ::create();                                                                        
    set_name("Snakeskin Armour");
    set("id", ({ "armour" }) );
    set("short", "%^RESET%^%^GREEN%^Sn%^ORANGE%^a%^GREEN%^k%^ORANGE%^e%^GREEN%^sk%^ORANGE%^i%^GREEN%^n %^ORANGE%^A%^GREEN%^rm%^ORANGE%^ou%^GREEN%^r");
    set("long", "%^RESET%^%^GREEN%^This armour was made from the skin of a basilisk." );
    set_type("armour");
    set_ac(9);
    set_limbs( ({ "torso", "right arm", "left arm" }) );
    set_weight(60);
    set_curr_value("gold", 250);
}
int query_auto_load() {
    if (this_player()->query_level() >= 36)
	return 1;
}
