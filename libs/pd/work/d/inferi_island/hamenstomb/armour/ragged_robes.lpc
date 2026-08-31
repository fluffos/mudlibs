#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    
void create() {
    ::create();                                                                        
    set_name("Ragged Robes");
    set("id", ({ "robe", "robes" }) );
    set("short", "%^ORANGE%^R%^WHITE%^a%^ORANGE%^gg%^WHITE%^e%^ORANGE%^d R%^WHITE%^o%^ORANGE%^b%^WHITE%^e%^ORANGE%^s%^RESET%^");
    set("long", "%^ORANGE%^These robes are old and begin to tear and become ragged.%^RESET%^" );
    set_type("robes");
    set_ac(1);
    set_limbs( ({ "torso", "right arm", "left arm", "left leg", "right leg" }) );
    set_weight(15);
    set_curr_value("gold", 34);
}
int query_auto_load() {
    if (this_player()->query_level() >= 10)
	return 1;
}
