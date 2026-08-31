#include <std.h>
#include <amun.h>
inherit WEAPON;                                                                   
void create() {
    ::create();                                                                       
    set_name("Split Spear");
    set("id", ({ "spear" }) );
    set("short", "%^BOLD%^%^BLACK%^Spl%^WHITE%^it Sp%^BLACK%^ear");
    set("long", "%^BOLD%^%^BLACK%^Used normally by royalty, this spear is split to look like a large fork.  It is usually used in combat that entertains the King; but is, nevertheless, a deadly and sharp weapon." );
    set_type("projectile");
    set_weight(12);
    set_curr_value("gold", 135);
    set_wc(12);
    set_type("projectile");
    set("skill level", 155);
}
int query_auto_load() {
    if (this_player()->query_level() >= 40)
	return 1;
}
