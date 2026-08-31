#include <std.h>
inherit ARMOUR;

void create() {
::create();
set_name("soldier helmet");
set_short("%^YELLOW%^Heavy Bronze Helmet%^RESET%^");
set_long("A plain helmet of simple design. There are many scratches from battle wear and tear. The helmet seems to be able to withstand many hits.");
set_wear("You try harder to hold your head up as the helmet weighs you down.");
set_remove("You feel unsafe and much lighter.");
set_id(({"helmet"}));
set_ac(5);
set_weight(30);
set_curr_value("electrum",150);
set_type("helmet");
set_limbs(({"head"}));
}

int query_auto_load() { if (this_player()->query_level() >= 20) return 1; }
