#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    						void create() {
    ::create();                                                                        				set_name("Belt of Clouds");
    set("id", ({ "belt", "belt of clouds", "clouds", "cloud" }) );
    set("short", "%^BOLD%^%^WHITE%^B%^CYAN%^e%^WHITE%^lt %^CYAN%^o%^WHITE%^f Cl%^CYAN%^ou%^WHITE%^ds%^RESET%^");
    set("long", "%^BOLD%^%^CYAN%^Even though this belt is made of clouds, the angels made it strong with thier magics.%^RESET%^" );
    set_type("belt");
    set_ac(3);
    set_limbs( ({ "torso" }) );
    set_weight(5);
    set_curr_value("gold", 150);
}
int query_auto_load() {
    if (this_player()->query_level() >= 30)
	return 1;
}
