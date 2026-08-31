#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_properties( (["no steal" : 1]) );
    set_name("badge");
    set("id", ({ "chip", "chocolate chip" }) );
    set("short", "%^BOLD%^%^BLACK%^C%^RESET%^%^WHITE%^h%^BOLD%^%^BLACK%^o%^RESET%^%^WHITE%^c%^BOLD%^%^BLACK%^o%^RESET%^%^WHITE%^l%^BOLD%^%^BLACK%^a%^RESET%^%^WHITE%^t%^BOLD%^%^BLACK%^e %^RESET%^%^WHITE%^C%^BOLD%^%^BLACK%^h%^RESET%^%^WHITE%^i%^BOLD%^%^BLACK%^p%^RESET%^");
    set("long", "%^BOLD%^This Chocolate Chip is to be worn only by Cookie. Deeeelicious!%^RESET%^");
    set_limbs( ({ "torso" }) );
    set_type("badge");
}

int query_auto_load() {
    if(this_player()->query_name() == "cookie")
	return 1;
}
