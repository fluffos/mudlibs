#include <std.h>
#include <amun.h>
inherit WEAPON;                                                                   
void create() {
    ::create();                                                                       
    set_name("Flint Knife");
    set("id", ({ "knife" }) );
    set("short", "%^BOLD%^%^BLACK%^Flint Knife");
    set("long", "%^BOLD%^%^BLACK%^This knife is good when wanting to surprise your %^RESET%^%^RED%^enemy%^BOLD%^%^BLACK%^, they are small and can sink into you opponent with ease." );
    set_type("knife");
    set_weight(10);
    set_curr_value("gold", 200);
    set_wc(9);
    set_type("knife");
    set("skill level", 150);
}
int query_auto_load() {
    if (this_player()->query_level() >= 25)
	return 1;
}
