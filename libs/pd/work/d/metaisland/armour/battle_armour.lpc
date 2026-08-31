#include <std.h>
#include <metallicana.h>
inherit ARMOUR;
void create() {
    ::create();
    set_name("battle armour");
    set_short("%^RED%^Bat%^BOLD%^%^BLACK%^tle Arm%^RESET%^%^RED%^our%^RESET%^");
    set_long("This is old kobold battle armour it might protect you.");
    set_id(({"battle armour", "armour"}));
    set_ac(12);
    set_weight(32);
    set_curr_value("gold",149);
    set_type("armour");
    set_limbs(({"torso", "left arm", "right arm"}));
}
int query_auto_load() {
if (this_player()->query_level() > 44) return 1;
}
