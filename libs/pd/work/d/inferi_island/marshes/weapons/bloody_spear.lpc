#include <std.h>
#include <amun.h>
inherit WEAPON;
void create() {
    ::create(); 
    set_name("Bloody Spear");
    set("id", ({ "spear" }) );
    set("short", "%^BOLD%^%^RED%^Bloo%^RESET%^%^RED%^dy S%^BOLD%^%^RED%^pear%^RESET%^");
    set("long", "%^BOLD%^%^RED%^This spear was used by the undead to defend themselves through life, guess it did not work out.%^RESET%^" );
    set_type("projectile");
    set_weight(12);
    set_curr_value("gold", 25);
    set_wc(2);
    set_type("projectile");
    set_decay_rate(200);
    set("skill level", 10);
}
int query_auto_load() {
    if (this_player()->query_level() >= 10)
	return 1;
}
