#include <std.h>
#include <metallicana.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("Belt");
    set_short("%^BOLD%^%^BLUE%^W%^WHITE%^a%^BLUE%^t%^WHITE%^e%^BLUE%^r %^BOLD%^%^BLUE%^B%^WHITE%^e%^BLUE%^l%^WHITE%^t%^RESET%^");
    set_long("The belt is made from the hide of a water snake.");
    set_id(({"belt", "water belt"}));
    set_ac(2);
    set_weight(5);
    set_curr_value("gold",49);
    set_type("belt");
    set_limbs(({"torso"}));
}
int query_auto_load() {
     if (this_player()->query_level() > 44) return 1;
}
