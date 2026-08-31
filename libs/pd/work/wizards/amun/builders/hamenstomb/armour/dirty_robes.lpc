#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    
void create() {
    ::create();                                                                        
    set_name("Dirty Robes");
    set("id", ({ "robe", "robes" }) );
    set("short", "%^ORANGE%^Dir%^WHITE%^ty Ro%^ORANGE%^bes");
    set("long", "It looks as if the person wearing these robes was playing in the %^ORANGE%^mud %^WHITE%^for quite some time." );
    set_type("robes");
    set_ac(1);
    set_limbs( ({ "torso", "right arm", "left arm", "left leg", "right leg" }) );
    set_weight(15);
    set_curr_value("gold", 22);
}
int query_auto_load() {
    if (this_player()->query_level() >= 10)
	return 1;
}
