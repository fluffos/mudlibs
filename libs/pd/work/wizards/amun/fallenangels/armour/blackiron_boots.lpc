#include <std.h>
#include <amun.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("Blackiron Boots");
    set_id( ({ "blackiron boots", "boots", "blackiron" }) );
    set_short("%^BOLD%^%^BLACK%^B%^RED%^l%^BLACK%^a%^RED%^c%^BLACK%^k%^RED%^i%^BLACK%^r%^RED%^o%^BLACK%^n %^RED%^B%^BLACK%^o%^RED%^o%^BLACK%^t%^RED%^s%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^These blackiron boots were built from the fires of %^RED%^hell%^BLACK%^. It is very strong and hard to penetrate.%^RESET%^");
    set_type("boots");
    set_ac(6);
    set_limbs( ({ "right foot", "left foot" }) );
    set_weight(20);
    set_curr_value("gold", 100);
}
int query_auto_load() {
    if (this_player()->query_level() >= 40)
	return 1;
}
