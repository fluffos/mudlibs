#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    
void create() {
    ::create();                                                                        
    set_name("Gold Plated Armour");
    set("id", ({ "armour" }) );
    set("short", "%^BOLD%^%^YELLOW%^Gold Plated Armour");
    set("long", "%^BOLD%^%^YELLOW%^The townspeople gave this armour to the King as a gift." );
    set_type("armour");
    set_ac(6);
    set_limbs( ({ "torso", "right arm", "left arm" }) );
    set_weight(80);
    set_curr_value("gold", 175); 
}
int query_auto_load() {
    if (this_player()->query_level() >= 46)
	return 1;
}
