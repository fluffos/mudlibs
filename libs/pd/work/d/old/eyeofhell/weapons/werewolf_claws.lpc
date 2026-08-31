#include <std.h>
#include <amun.h>
inherit WEAPON;                                                                    						void create() {
    ::create();                                                                        				 set_name("Werewolf Claws");
    set("id", ({ "claw", "claws","werewold claws", "knife", "dagger" }) );
    set("short", "%^BOLD%^%^BLACK%^Were%^WHITE%^wolf C%^BLACK%^laws%^RESET%^");
    set("long", "%^BOLD%^%^BLACK%^These claws were severed off of a hell beast.  They are extreamly sharp.%^RESET%^" );
    set_type("knife");
    set_weight(30);
    set_curr_value("gold", 150);
    set_wc(11);
    set_type("knife");
    set("skill level", 175);
}
int query_auto_load() {
    if (this_player()->query_level() >= 40)
	return 1;
}
