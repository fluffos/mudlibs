#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                         
void create() {
    ::create();                                                         
    set_name("Diaper");
    set("id", ({ "diaper"}) );
    set("short", "%^BOLD%^%^WHITE%^Diaper%^RESET%^");
    set("long", "%^BOLD%^%^WHITE%^This diaper was made by the God of Love.%^RESET%^");
    set_type("pants");
    set_ac(1);
    set_limbs( ({ "right leg", "left leg"}) );
    set_weight(5);
    set_curr_value("gold", 50);  
}
int query_auto_load() {
    if (this_player()->query_level() >= 10)
	return 1;
}
