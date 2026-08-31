#include <std.h>
inherit ARMOUR;

void create() {
::create();
    set_name("helm");
    set_short("%^BLUE%^Cr%^RED%^ims%^BOLD%^%^BLACK%^on H%^RESET%^%^BLUE%^el%^RED%^m");
    set_long("The helm is worn by the %^RED%^gu%^YELLOW%^ar%^RED%^di%^GREEN%^an%^RESET%^ of %^RED%^hell.");
    set_id(({"helm", "helmet", "crimson helm"}));
    set_ac(6);
    set_mass(8);
    set_value(200);
    set_type("armour");
    set_limbs(({"head"}));
}
int query_auto_load() { if (this_player()->query_level() > 19) return 1; }
