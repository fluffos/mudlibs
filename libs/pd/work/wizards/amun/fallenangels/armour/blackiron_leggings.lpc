#include <std.h>
#include <amun.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("Blackiron Leggings");
    set_id( ({ "blackiron leggings", "leggings", "blackiron" }) );
    set_short("%^BOLD%^%^BLACK%^B%^RED%^l%^BLACK%^a%^RED%^c%^BLACK%^k%^RED%^i%^BLACK%^r%^RED%^o%^BLACK%^n %^RED%^L%^BLACK%^e%^RED%^g%^BLACK%^g%^RED%^i%^BLACK%^n%^RED%^g%^BLACK%^s%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^These blackiron leggings were built from the fires of %^RED%^hell%^BLACK%^. It is very strong and hard to penetrate.%^RESET%^");
    set_type("leggings");
    set_ac(4);
    set_limbs( ({ "right leg", "left leg" }) );
    set_weight(20);
    set_curr_value("gold", 100);
}
int query_auto_load() {
    if (this_player()->query_level() >= 40)
	return 1;
}
