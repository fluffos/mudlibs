#include <std.h>
#include <amun.h>
inherit WEAPON;                                                         
void create() {
    ::create();                                                             
    set_name("Bow of Love");
    set("id", ({ "bow", "bow of love" }) );
    set("short", "%^BOLD%^%^WHITE%^Bow of l%^MAGENTA%^o%^WHITE%^v%^MAGENTA%^e%^RESET%^");
    set("long", "%^BOLD%^%^WHITE%^This magical bow was made from pure love.%^RESET%^" );
    set_type("bow");
    set_weight(20);
    set_curr_value("gold", 175);
    set_wc(2);
    set_type("ranged");
    set("skill level", 100);
}
int query_auto_load() {
    if (this_player()->query_level() >= 30)
	return 1;
}
