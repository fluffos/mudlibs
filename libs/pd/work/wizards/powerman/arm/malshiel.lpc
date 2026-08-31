#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("shield of malcolm's army");
    set_short("Shield of %^BLUE%^Malcolm's Army%^RESET%^");
    set_long("This shield has the coat of arms of Malcolm's army on it.");
    set_wear("You seem more welcomed amongst the battlefields.");
    set_remove("You feel unsafe and much lighter.");
    set_id(({"shield"}));
    set_ac(2);
    set_weight(20);
    set_curr_value("electrum",250);
    set_type("shield");
    set_limbs(({"left arm", "right arm"}));
}
int query_auto_load() { if (this_player()->query_level() >= 20) return 1; }
