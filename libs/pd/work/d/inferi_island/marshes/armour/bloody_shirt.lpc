#include <std.h>
#include <amun.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("Bloody Shirt");
    set("id", ({ "shirt" }) );
    set("short", "%^BOLD%^%^RED%^Bloo%^RESET%^%^RED%^dy S%^BOLD%^%^RED%^hirt%^RESET%^");
    set("long", "%^BOLD%^%^RED%^This bloo%^RESET%^%^RED%^dy s%^BOLD%^%^RED%^hirt is weighed down with thick blood.%^RESET%^" );
    set_type("shirt");
    set_ac(2);
    set_limbs( ({ "torso", "left arm", "right arm" }) );
    set_weight(3);
    set_curr_value("gold", 10);  
}
int query_auto_load() {
    if (this_player()->query_level() >= 10)
	return 1;
}
