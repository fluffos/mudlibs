#include <std.h>
inherit ARMOUR;

void create() {
  ::create();
    set_name("bracer");
    set_short("%^BOLD%^WHITE%^W%^RESET%^ORANGE%^inged %^BOLD%^WHITE%^B%^RESET%^ORANGE%^racer");
    set_long("A sturdy bracer made of steel, it has many intricate designs etched into it, and on the outer side a silvery wing extends outwards. It fits your left arm.");
    set_id(({"bracer", "winged bracer"}));
    set_ac(1);
    set_weight(10);
    set_curr_value("gold",150);
    set_type("bracers");
    set_limbs(({"left arm"}));
}

int query_auto_load() {
    if(this_player()->query_guild() == "illuminati") return 1;
    return 0;
}
