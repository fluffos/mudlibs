#include <std.h>
#include <amun.h>
inherit WEAPON;
int weapon_hit();
int can_wield();
void create() {
    ::create();
    set_name("Blade Of Fire");
    set("id", ({ "sword", "blade" }) );
    set("short", "%^BOLD%^%^BLACK%^Bl%^RED%^a%^BLACK%^d%^RED%^e O%^BLACK%^f F%^RED%^i%^BLACK%^r%^RED%^e%^RESET%^");
    set("long", "%^BOLD%^%^RED%^This blade is well crafted with the finest steel within the eye of hell.%^RESET%^" );
    set_weight(40);
    set_curr_value("gold", 200);
    set_wc(12);
    set_type("blade");
    set_element("fire", 20);
    set_element("ice", -20);
    set_decay_rate(200);
    set("skill level", 250);
}
int query_auto_load() {
    if (this_player()->query_level() >= 45)
	return 1;
}
