#include <std.h>
#include <amun.h>
inherit ARMOUR;       
void create() {
    ::create();                                                                        				set_name("Cloak of the light");
    set("id", ({ "cloak", "cloak of the", "cloak of", "cloak of the light", "of the light", "the light", "light" }) );
    set("short", "%^BOLD%^%^WHITE%^Cl%^RESET%^%^WHITE%^oa%^BOLD%^%^WHITE%^k %^RESET%^%^WHITE%^o%^BOLD%^%^WHITE%^f th%^RESET%^%^WHITE%^e %^BOLD%^%^WHITE%^L%^RESET%^%^WHITE%^i%^BOLD%^%^WHITE%^ght%^RESET%^");
    set("long", "%^BOLD%^%^WHITE%^This %^BOLD%^%^WHITE%^cl%^RESET%^%^WHITE%^oa%^BOLD%^%^WHITE%^k is very light and offers good protection." );
    set_type("cloak");
    set_ac(4);
    set_limbs( ({ "torso", "right arm", "left arm" }) );
    set_weight(34);
    set_curr_value("gold", 200); 
}
int query_auto_load() {
    if (this_player()->query_level() >= 40)
	return 1;
}
