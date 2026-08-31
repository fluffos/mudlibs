#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    
void create() {
    ::create();                                                                        
    set_name("Golden Corselets");
    set("id", ({ "corselet", "leggings" }) );
    set("short", "%^BOLD%^%^YELLOW%^Golden Corselet");
    set("long", "%^BOLD%^%^YELLOW%^Gold chains linked together to make these corselets." );
    set_type("leggings");
    set_ac(4);
    set_limbs( ({ "right leg", "left leg" }) );
    set_weight(20);
    set_curr_value("gold", 200);
}
int query_auto_load() {
    if (this_player()->query_level() >= 40)
	return 1;
}
