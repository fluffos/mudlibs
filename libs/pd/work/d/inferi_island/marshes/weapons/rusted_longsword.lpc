#include <std.h>
#include <amun.h>
inherit WEAPON;
int weapon_hit();
int can_wield();
void create() {
    ::create();
    set_name("Rusted Longsword");
    set("id", ({ "sword" }) );
    set("short", "%^ORANGE%^Rusted Longsword%^RESET%^");
    set("long", "%^ORANGE%^This longsword has seen many battles and is probably too worn to be used for a long time.%^RESET%^" );
    set_weight(15);
    set_curr_value("gold", 25);
    set_wc(3);
    set_type("blade");
    set_decay_rate(200);
    set("skill level", 10);
}
int query_auto_load() {
    if (this_player()->query_level() >= 10)
	return 1;
}
