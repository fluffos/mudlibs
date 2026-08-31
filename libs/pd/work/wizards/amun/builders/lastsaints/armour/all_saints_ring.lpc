#include <std.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("ring");
    set_short("%^BOLD%^%^BLACK%^A%^WHITE%^l%^BLACK%^l %^WHITE%^S%^BLACK%^a%^WHITE%^i%^BLACK%^n%^WHITE%^t%^BLACK%^s %^WHITE%^R%^BLACK%^i%^WHITE%^n%^BLACK%^g%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This ring was given to the %^WHITE%^S%^BLACK%^a%^WHITE%^i%^BLACK%^n%^WHITE%^t%^BLACK%^s as a gift from the %^WHITE%^God %^BLACK%^they serve.%^RESET%^");
    set_id(({"ring", "saints ring", "all saints ring"}));
    set_ac(2);
    set_weight(3);
    set_curr_value("gold", 172);
    set_type("ring");
    set_limbs(({"left hand", "right hand"}));
}
int query_auto_load() {
    if(this_player()->query_guild() != "last saints") return 0;
    return 1;
}
