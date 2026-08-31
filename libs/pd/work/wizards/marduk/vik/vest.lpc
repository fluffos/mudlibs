#include <std.h>
inherit ARMOUR;

void create() {
::create();
    set_name("vest");
    set_short("a dirty vest");
    set_long("This is the vest of a beggar. The vest is raggedy and dirty. "
	"It looks useless for armour.");
    set_id(({"vest", "dirty vest", "armour", "armor"}));
    set_ac(2);
    set_mass(6);
    set_value(50);
    set_type("armour");
    set_limbs(({"torso", "left arm", "right arm"}));
}
int query_auto_load() { if (this_player()->query_level() > 1) return 1; }
