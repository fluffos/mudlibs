#include <std.h>
#include <amun.h>
inherit WEAPON;
void create() {
    ::create();
    set_name("Bronze Sword");
    set("id", ({ "sword" }) );
    set("short", "%^ORANGE%^Bronze %^WHITE%^Sword%^RESET%^");
    set("long", "%^ORANGE%^This sword is used by those who protect the %^WHITE%^King, %^ORANGE%^it is sharpened and slices through enemies easily.%^RESET%^" );
    set_weight(25);
    set_curr_value("gold", 110);
    set_wc(8);
    set_type("blade");
    set_decay_rate(5000);
    set("skill level", 250);
}
int query_auto_load() {
    if (this_player()->query_level() >= 40)
	return 1;
}
