#include <std.h>
inherit ARMOUR;

void create() {
::create();
    set_name("cloak");
    set_short("%^RED%^C%^BOLD%^%^BLACK%^loak %^RED%^o%^BLACK%^f %^RESET%^%^RED%^C%^BOLD%^%^BLACK%^haos");
    set_long("This cloak was made specially for the freak Salazar. "
	"It symbolizes the chaotic way of the artrell.");
    set_id(({"cloak", "cloak of chaos"}));
    set_ac(9);
    set_mass(6);
    set_value(350);
    set_type("cloak");
    set_limbs(({"torso", "first arm", "second arm", "third arm", "fourth arm"}));
}
int query_auto_load() { if (this_player()->query_level() > 10) return 1; }
