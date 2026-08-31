#include <std.h>
#include <amun.h>
inherit WEAPON;
int weapon_hit();
int can_wield();
void create() {
    ::create();
    set_name("Wand");
    set("id", ({ "wand", "staff" }) );
    set("short", "%^RESET%^%^ORANGE%^Wand");
    set("long", "%^RESET%^%^ORANGE%^This wand belongs to Riddle, It's magical powers will only work for him.%^RESET%^" );
    set_weight(12);
    set_curr_value("gold", 15);
    set_wc(3);
    set_type("staff");
    set("skill level", 75);
}
int query_auto_load() {
    if (this_player()->query_level() >= 10)
	return 1;
}
