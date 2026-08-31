#include <std.h>
#include <amun.h>
inherit WEAPON;
int weapon_hit();
int can_wield();
void create() {
    ::create();
    set_name("Broken Shortsword");
    set("id", ({ "sword" }) );
    set("short", "%^BOLD%^%^BLACK%^Bronze Shortsword%^RESET%^");
    set("long", "%^BOLD%^%^BLACK%^Although this shortsword is broken in half it is still sharp.%^RESET%^" );
    set_weight(10);
    set_curr_value("gold", 25);
    set_wc(1);
    set_type("blade");
    set_decay_rate(200);
    set("skill level", 1);
}
int query_auto_load() {
    if (this_player()->query_level() >= 10)
	return 1;
}
