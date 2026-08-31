#include <std.h>
#include <amun.h>
inherit WEAPON;
void create() {
    ::create();
    set_name("Great Sword");
    set("id", ({ "sword" }) );
    set("short", "%^RESET%^%^ORANGE%^Tarnished %^RESET%^Great Sword%^RESET%^");
    set("long", "%^RESET%^%^ORANGE%^This great sword has become tarnished with age. The hilt is loose and half worn away.%^RESET%^" );
    set_type("blade");
    set_weight(35);
    set_curr_value("gold", 25);
    set_wc(2);
    set_type("blade");
    set_decay_rate(200);
    set("skill level", 15);
}
int query_auto_load() {
    if (this_player()->query_level() >= 10)
	return 1;
}
