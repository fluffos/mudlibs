#include <std.h>
#include <amun.h>
inherit WEAPON;                                                                   
void create() {
    ::create();                                                                       
    set_name("Cutting Axe");
    set("id", ({ "axe" }) );
    set("short", "Cutting Axe");
    set("long", "This Axe is used mainly as a throwing tool, they are very accurate and can be good in hacking.  The handle is light and the blade is sharp." );
    set_type("axe");
    set_weight(14);
    set_curr_value("gold", 100);
    set_wc(5);
    set_type("axe");
    set("skill level", 100);
}
int query_auto_load() {
    if (this_player()->query_level() >= 24)
	return 1;
}
