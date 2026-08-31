#include <std.h>
inherit WEAPON;

void create() {
::create();
    set_name("axe");
    set_short("%^BOLD%^%^BLACK%^Do%^WHITE%^ub%^BLACK%^le %^WHITE%^b%^BLACK%^la%^WHITE%^d%^BLACK%^ed a%^WHITE%^xe%^RESET%^");
    set_long("The axe looks awesomely %^BOLD%^%^BLACK%^de%^WHITE%^ad%^BLACK%^ly%^RESET%^.  It's rather large "
	"and requires two hands to wield it.");
    set_id(({"axe", "double bladed axe"}));
    set_mass(40);
    set_value(900);
    set_type("axe");
    set_hands(2);
    set_wc(17);
    set_ac(2);
}
int query_auto_load() { if (this_player()->query_level() > 19) return 1; }
