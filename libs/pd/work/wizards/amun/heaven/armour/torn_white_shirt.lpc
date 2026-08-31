#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    
void create() {
    ::create();                                                                        
    set_name("Torn White Shirt");
    set("id", ({ "shirt", "torn white shirt" }) );
    set("short", "T%^ORANGE%^o%^RESET%^rn White S%^ORANGE%^h%^RESET%^irt");
    set("long", "This shirt was once made out of pure holiness and love.");
    set_type("shirt");
    set_ac(2);
    set_limbs( ({ "right arm", "left arm", "torso" }) );
    set_weight(20);
    set_curr_value("gold", 100);  
}
int query_auto_load() {
    if (this_player()->query_level() >= 25)
	return 1;
}
