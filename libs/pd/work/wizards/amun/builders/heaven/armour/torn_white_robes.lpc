#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    
void create() {
    ::create();                                                                        
    set_name("Torn White Robes");
    set("id", ({ "robe", "robes", "torn white robes", "torn white robe" }) );
    set("short", "T%^ORANGE%^o%^RESET%^rn White R%^ORANGE%^o%^RESET%^bes");
    set("long", "These robes were once made out of pure holiness and love, but now belong to the fallen." );
    set_type("robes");
    set_ac(2);
    set_limbs( ({ "torso", "right arm", "left arm", "left leg", "right leg" }) );
    set_weight(30);
    set_curr_value("gold", 100); 
}
int query_auto_load() {
    if (this_player()->query_level() >= 25)
	return 1;
}
