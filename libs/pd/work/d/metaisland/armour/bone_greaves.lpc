#include <std.h>
#include <metallicana.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("greaves");
    set_short("%^BOLD%^%^BLACK%^B%^WHITE%^on%^BLACK%^e Gr%^WHITE%^ea%^BLACK%^ves%^RESET%^");
    set_long("These boots are made from canine bone, with the inside filled with leaves for comfort.");
    set_id(({"greaves", "bone greaves", "boots"}));
    set_ac(7);
    set_weight(11);
    set_curr_value("gold",145);
    set_type("boots");
    set_limbs(({"left foot", "right foot"}));
}
int query_auto_load() {
if (this_player()->query_level() > 44) return 1;
}
