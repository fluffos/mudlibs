#include <std.h>
#include <amun.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("bracers");
    set_short("%^BOLD%^%^YELLOW%^Lux %^RESET%^%^ORANGE%^Bracers");
    set_long("%^BOLD%^%^WHITE%^These bracers are made of pure energy. Although they are incredibly light, they are very strong and offer decent protection.%^RESET%^");
    set_id(({"bracers", "bracer", "lux", "lux bracers"}));
    set_ac(1);
    set_weight(10);
    set_curr_value("gold",150);
    set_type("bracers");
    set_limbs(({"left arm", "right arm"}));
}
int query_auto_load() {
    if(this_player()->query_original_guild() == "lastsaints") return 1;
    return 0;
}
