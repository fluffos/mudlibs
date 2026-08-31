#include <std.h>
#include <amun.h>
inherit WEAPON;                                                                    						void create() {
    ::create();                                                                        				 set_name("Inferi Axe");
    set("id", ({ "axe" }) );
    set("short", "%^RESET%^%^RED%^Inf%^BOLD%^%^WHITE%^e%^RESET%^%^RED%^ri Ax%^BOLD%^%^WHITE%^e%^RESET%^");
    set("long", "This axe is not as sharp as what it used to be, but is still good during combat." );
    set_type("axe");
    set_weight(20);
    set_curr_value("gold", 100);
    set_wc(5);
    set_type("axe");
    set("skill level", 100);
}
int query_auto_load() {
    if (this_player()->query_level() >= 36)
	return 1;
}
