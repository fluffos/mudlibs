#include <std.h>
#include <amun.h>
inherit WEAPON;
void create() {
    ::create();
    set_name("Golden Dagger");
    set("id", ({ "dagger" }) );
    set("short", "%^BOLD%^%^YELLOW%^Golden Dagger%^RESET%^");
    set("long", "%^BOLD%^%^BLACK%^With a black leather handle and a %^YELLOW%^dagger made of solid gold%^BLACK%^, the Magi gave this %^BOLD%^dagger %^BLACK%^to the King as it shows greatness, like the King they serve.%^RESET%^" );
    set_type("dagger");
    set_weight(30);
    set_curr_value("gold", 220);
    set_wc(11);
    set_type("knife");
    set_wield("%^BOLD%^%^YELLOW%^You feel royal as you wield this weapon.%^RESET%^");
    set_unwield("%^BOLD%^%^YELLOW%^You feel the roalty leave your senses.%^RESET%^");
    set("skill level", 200);
}
int query_auto_load() {
    if (this_player()->query_level() >= 50)
	return 1;
}
