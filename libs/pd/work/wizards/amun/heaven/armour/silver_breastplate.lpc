#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    						void create() {
    ::create();                                                                        				set_name("Silver Breastplate");
    set("id", ({ "silver breastplate", "armour", "breastplate" }) );
    set("short", "%^BOLD%^%^WHITE%^S%^RESET%^%^WHITE%^i%^BOLD%^%^WHITE%^l%^RESET%^%^WHITE%^v%^BOLD%^%^WHITE%^e%^RESET%^%^WHITE%^r %^BOLD%^%^WHITE%^B%^RESET%^%^WHITE%^r%^BOLD%^%^WHITE%^e%^RESET%^%^WHITE%^a%^BOLD%^%^WHITE%^s%^RESET%^%^WHITE%^t%^BOLD%^%^WHITE%^p%^RESET%^%^WHITE%^l%^BOLD%^%^WHITE%^a%^RESET%^%^WHITE%^t%^BOLD%^%^WHITE%^e%^RESET%^");
    set("long", "%^BOLD%^%^WHITE%^Made to aide those in battle, this %^BOLD%^%^WHITE%^b%^RESET%^%^WHITE%^r%^BOLD%^%^WHITE%^e%^RESET%^%^WHITE%^a%^BOLD%^%^WHITE%^s%^RESET%^%^WHITE%^t%^BOLD%^%^WHITE%^p%^RESET%^%^WHITE%^l%^BOLD%^%^WHITE%^a%^RESET%^%^WHITE%^t%^BOLD%^%^WHITE%^e offers much protection.%^RESET%^" );
    set_type("body armour");
    set_ac(10);
    set_limbs( ({ "torso", "right arm", "left arm", "right leg", "left leg" }) );
    set_weight(100);
    set_curr_value("gold", 300);
}
int query_auto_load() {
    if (this_player()->query_level() >= 40)
	return 1;
}
