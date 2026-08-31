#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("tunic");
    set_short("%^BOLD%^%^CYAN%^T%^BLUE%^u%^CYAN%^n%^BLUE%^i%^CYAN%^c%^RESET%^");
    set_long("%^BOLD%^%^CYAN%^This %^BLUE%^checkered %^CYAN%^tunic %^BLUE%^does %^CYAN%^not %^BLUE%^offer %^CYAN%^much %^BLUE%^protection.%^RESET%^");
    set_id(({"tunic"}));
    set_ac(1);
    set_weight(3);
    set_curr_value("gold", 10+random(5));
    set_type("tunic");
    set_limbs(({"torso"}));
}

int query_auto_load() {
    if(this_player()->query_level() > 3) return 1;
    return 0;
}
