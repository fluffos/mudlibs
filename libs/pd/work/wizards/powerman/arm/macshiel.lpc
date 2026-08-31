#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("shield of macbeth's army");
    set_short("Shield of %^RED%^Macbeth's Army%^RESET%^");
    set_long("This shield has the coat of arms of Macbeth's army on it.");
    set_wear("You seem less welcomed amongst the battlefields.");
    set_remove("You feel unsafe and much lighter.");
    set_id(({"shield"}));
    set_ac(3);
    set_weight(20);
    set_curr_value("electrum",250);
    set_type("shield");
    set_limbs(({"left arm", "right arm"}));
}
int query_auto_load() { if (this_player()->query_level() >= 20) return 1; }
