#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("bronze gauntlets");
    set_short("%^RESET%^%^ORANGE%^Bronze Gauntlets%^RESET%^");
    set_long("This set of gauntlets is made out of sections of bronze for the "
      "best protection.  There is worn out leather paddings inside the gauntlets for "
      "comfort.");
    set_wear("Your hands don't move as quickly as you feel cramped.");
    set_remove("Your hands start to spasm from relaxation.");
    set_id(({"gauntlets", "bronze gauntlets","gloves"}));
    set_ac(3);
    set_weight(30);
    set_curr_value("electrum",250);
    set_type("gloves");
    set_limbs(({"left hand", "right hand"}));
}
int query_auto_load() { if (this_player()->query_level() >= 20) return 1; }
