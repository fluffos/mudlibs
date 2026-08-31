#include <std.h>
#include <amun.h>
inherit WEAPON;
void create() {
    ::create();
    set_name("Ancient Hatchet");
    set("id", ({ "hatchet", "axe" }) );
    set("short", "%^ORANGE%^Anc%^WHITE%^i%^ORANGE%^ent Hat%^WHITE%^c%^ORANGE%^het%^RESET%^");
    set("long", "%^ORANGE%^Good for hacking, this hatchet's %^WHITE%^blade %^ORANGE%^comes to a point at the top allowing you to use it to pick your enemies.%^RESET%^" );
    set_type("axe");
    set_decay_rate(1000);
    set_weight(20);
    set_curr_value("gold", 135);
    set_wc(10);
    set_type("axe");
    set("skill level", 150);
}
int query_auto_load() {
    if (this_player()->query_level() >= 28)
	return 1;
}
