#include <std.h>
#include <amun.h>
inherit ARMOUR;                                                                    						void create() {
    ::create();                                                                        				set_name("Helm Of Clouds");
    set("id", ({ "helm" }) );
    set("short", "%^BOLD%^%^WHITE%^H%^CYAN%^e%^WHITE%^lm %^CYAN%^o%^WHITE%^f Cl%^CYAN%^ou%^WHITE%^ds%^RESET%^");
    set("long", "%^BOLD%^%^CYAN%^Even though this helm is made of clouds, the angels made it strong with thier magics.%^RESET%^" );
    set_type("helmet");
    set_ac(4);
    set_limbs( ({ "head" }) );
    set_weight(5);
    set_curr_value("gold", 200);
}
int query_auto_load() {
    if (this_player()->query_level() >= 30)
	return 1;
}
