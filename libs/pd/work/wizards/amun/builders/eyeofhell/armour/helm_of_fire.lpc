#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                
void create() {
    ::create();                                                                    
    set_name("Helm Of Fire");
    set("id", ({ "helm" }) );
    set("short", 
      "%^RESET%^%^ORANGE%^H%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^l%^RED%^m %^ORANGE%^O%^RED%^f %^ORANGE%^F%^BOLD%^%^BLACK%^i%^RESET%^%^ORANGE%^r%^RED%^e%^RESET%^");
    set("long", "%^RESET%^%^RED%^Made in the Inferi, this helm is lined with fire.%^RESET%^" );
    set_type("helmet");
    set_ac(4);
    set_limbs( ({ "head" }) );
    set_weight(10);
    set_curr_value("gold", 200);
    set_wear("%^BOLD%^%^RED%^Your head feels hot like it is going to set on fire as you wear your helm.\n");
    set_remove("%^BOLD%^%^RED%^Your head feel cooler as your remove your helm.");
}
int query_auto_load() {
    if (this_player()->query_level() >= 50)
	return 1;
}
