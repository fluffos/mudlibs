#include <std.h>
inherit ARMOUR;

void create() {
::create();
set_name("cape");
set_short("%^MAGENTA%^A %^RED%^Finely Crafted %^BOLD%^Cape%^RESET%^");
set_long("This cape of stunning quality still looks quite new after wear and
tear from war. It is made of a fine rugged but comfortable cloth.");
set_wear("You feel proud as you don the cape.");
set_remove("You swing the cape aroundy your body to remove it.");
set_id(({"cape"}));
set_ac(2);
set_weight(30);
set_curr_value("electrum",150);
set_type("cloak");
set_limbs(({"head", "torso", "left leg", "right leg"}));
}
int query_auto_load() { if (this_player()->query_level() >= 20) return 1; }
