#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    
void create() {
    ::create();                                                                        
    set_name("Bronze Coatmail");
    set("id", ({ "coatmail", "armour" }) );
    set("short", "%^RESET%^%^ORANGE%^Bronze Coatmail%^RESET%^");
    set("long", "%^RESET%^%^ORANGE%^Armour made of bronze chain linked together.%^RESET%^" );
    set_type("body armour");
    set_ac(9);
    set_limbs( ({ "torso", "right arm", "left arm", "right leg", "left leg" }) );
    set_weight(100);
    set_curr_value("gold", 300);
}
int query_auto_load() {
    if (this_player()->query_level() >= 40)
	return 1;
}
