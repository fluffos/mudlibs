#include <std.h>
inherit ARMOUR;

void create() {
::create();
    set_name("skull helm");
    set_short("%^BOLD%^%^BLACK%^Sk%^WHITE%^ul%^BLACK%^l H%^WHITE%^el%^BLACK%^m%^RESET%^");
    set_long("This helm seems almost to be a mask, it "
	"was created from the bones of lost %^RED%^%^BOLD%^so%^BLACK%^ul%^RED%^s.");
    set_id(({"helm", "skull helm", "helmet"}));
    set_ac(6);
    set_mass(8);
    set_value(200);
    set_type("armour");
    set_limbs(({"head"}));
}
int query_auto_load() { if (this_player()->query_level() > 19) return 1; }
