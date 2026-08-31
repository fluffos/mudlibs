#include <std.h>
#include <amun.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("Blackiron Chestplate");
    set_id( ({ "blackiron chestplate", "armour", "chestplate", "blackiron" }) );
    set_short("%^BOLD%^%^BLACK%^B%^RED%^l%^BLACK%^a%^RED%^c%^BLACK%^k%^RED%^i%^BLACK%^r%^RED%^o%^BLACK%^n %^RED%^C%^BLACK%^h%^RED%^e%^BLACK%^s%^RED%^t%^BLACK%^p%^RED%^l%^BLACK%^a%^RED%^t%^BLACK%^e%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This blackiron chestplate was built from the fires of %^RED%^hell%^BLACK%^. It is very strong and hard to penetrate.%^RESET%^");
    set_type("armour");
    set_ac(10);
    set_limbs( ({ "torso", "right arm", "left arm" }) );
    set_weight(100);
    set_curr_value("gold", 250);
}
int query_auto_load() {
    if (this_player()->query_level() >= 40)
	return 1;
}
