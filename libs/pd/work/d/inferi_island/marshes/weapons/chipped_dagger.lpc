#include <std.h>
#include <amun.h>
inherit WEAPON;
void create() {
    ::create();
    set_name("Chipped Dagger");
    set("id", ({ "dagger" }) );
    set("short", "Chipped Dagger");
    set("long", "This dagger looks like it has been used for many things, this could be what caused it to chip." );
    set_type("dagger");
    set_weight(10);
    set_curr_value("gold", 25);
    set_wc(3);
    set_type("knife");
    set_decay_rate(200);
    set("skill level", 10);
}
int query_auto_load() {
    if (this_player()->query_level() >= 10)
	return 1;
}
