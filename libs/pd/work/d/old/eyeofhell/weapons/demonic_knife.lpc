#include <std.h>
#include <amun.h>
inherit WEAPON;                                                                    						void create() {
    ::create();                                                                        				 set_name("Demonic Knife");
    set("id", ({ "knife" }) );
    set("short", "%^BOLD%^%^BLACK%^D%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^m%^RESET%^%^RED%^o%^BOLD%^%^BLACK%^n%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^c %^RESET%^%^RED%^K%^BOLD%^%^BLACK%^n%^RESET%^%^RED%^i%^BOLD%^%^BLACK%^f%^RESET%^%^RED%^e%^RESET%^");
    set("long", "%^BOLD%^%^BLACK%^This knife is greatly used within the eye of hell.  It is good for those sneak attacks on your %^RESET%^%^RED%^enemies%^BOLD%^%^BLACK%^." );
    set_type("knife");
    set_weight(10);
    set_curr_value("gold", 200);
    set_wc(9);
    set_type("knife");
    set("skill level", 150);
}
int query_auto_load() {
    if (this_player()->query_level() >= 36)
	return 1;
}
