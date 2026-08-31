#include <std.h>
#include <metallicana.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("ragged pants");
    set_short("%^ORANGE%^Ragged Pants%^RESET%^");
    set_long("A pair of ragged pants, good for sneaking around in.");
    set_id(({"ragged pants", "pants"}));
    set_ac(2);
    set_weight(7);
    set_curr_value("gold",89);
    set_type("pants");
    set_limbs(({"left leg", "right leg"}));
}
int query_auto_load() {
if (this_player()->query_level() > 44) return 1;
}
