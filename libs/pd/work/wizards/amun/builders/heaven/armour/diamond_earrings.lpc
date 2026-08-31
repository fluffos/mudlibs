#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                         
void create() {
    ::create();                                                         
    set_name("Diamond Earrings");
    set("id", ({ "diamond earrings", "earrings"}) );
    set("short", "%^BOLD%^%^WHITE%^D%^RESET%^i%^BOLD%^%^WHITE%^a%^RESET%^m%^BOLD%^%^WHITE%^o%^RESET%^n%^BOLD%^%^WHITE%^d %^RESET%^E%^BOLD%^%^WHITE%^a%^RESET%^r%^BOLD%^%^WHITE%^r%^RESET%^i%^BOLD%^%^WHITE%^n%^RESET%^g%^BOLD%^%^WHITE%^s%^RESET%^");
    set("long", "%^BOLD%^%^WHITE%^These %^RESET%^earrings %^BOLD%^%^WHITE%^offer %^RESET%^heavenly %^BOLD%^%^WHITE%^protection %^RESET%^to %^BOLD%^%^WHITE%^the %^RESET%^ears %^BOLD%^%^WHITE%^of %^RESET%^anyone %^BOLD%^%^WHITE%^who %^RESET%^wears %^BOLD%^%^WHITE%^them.%^RESET%^");
    set_type("earrings");
    set_ac(1);
    set_limbs( ({ "head"}) );
    set_weight(3);
    set_curr_value("gold", 150);  
}
int query_auto_load() {
    if (this_player()->query_level() >= 40)
	return 1;
}
