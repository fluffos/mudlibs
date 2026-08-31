#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("dress");
    set_short("%^BOLD%^%^WHITE%^White Dress%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This is a plain white dress.%^RESET%^");
    set_id(({"dress"}));
    set_ac(1);
    set_weight(1);
    set_curr_value("gold", 8+random(13));
    set_type("dress");
    set_limbs(({"torso"}));
}

int query_auto_load() {
    if(this_player()->query_level() > 2) return 1;
    return 0;
}
