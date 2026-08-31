#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    
void create() {
    ::create();                                                                        
    set_name("Gold Plated Gauntlets");
    set("id", ({ "gloves", "gauntlets" }) );
    set("short", "%^BOLD%^%^YELLOW%^Gold Plated Gauntlets%^RESET%^");
    set("long", "%^BOLD%^%^YELLOW%^Forged in secret for the one and only King of the Tomb.%^RESET%^" );
    set_type("gloves");
    set_ac(2);
    set_limbs( ({ "right hand", "left hand" }) );
    set_weight(20);
    set_curr_value("gold", 120);
}
int query_auto_load() {
    if (this_player()->query_level() >= 46)
	return 1;
}
