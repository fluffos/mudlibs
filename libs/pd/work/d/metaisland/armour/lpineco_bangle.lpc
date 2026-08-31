#include <std.h>
#include <metallicana.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("pineco bangle");
    set_short("%^ORANGE%^Pi%^CYAN%^ne%^ORANGE%^co %^ORANGE%^Ba%^CYAN%^ng%^ORANGE%^le%^RESET%^");
    set_long("The bangles are made from hollowed out pincones, and fit snuggly
on the forearm.");
    set_id(({"pineco bangle", "bangle"}));
    set_ac(2);
    set_weight(16);
    set_curr_value("gold",183);
    set_type("bracelet");
    set_limbs(({"left arm"}));
}
int query_auto_load() {
if (this_player()->query_level() > 44) return 1;
}
