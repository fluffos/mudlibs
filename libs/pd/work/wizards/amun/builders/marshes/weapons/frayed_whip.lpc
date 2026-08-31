#include <std.h>
#include <amun.h>
inherit WEAPON;                                                                    						void create() {
    ::create();                                                                        				 set_name("Frayed Whip");
    set("id", ({ "whip" }) );
    set("short", "%^BOLD%^%^BLACK%^Frayed Whip");
    set("long", "%^BOLD%^%^BLACK%^This whipped has been used for quite some time.  It has begun to rot from the marsh." );
    set_type("projectile");
    set_weight(8);
    set_curr_value("gold", 25);
    set_wc(3);
    set_type("projectile");
    set_decay_rate(200);
    set("skill level", 15);
}
int query_auto_load() {
    if (this_player()->query_level() >= 10)
	return 1;
}
