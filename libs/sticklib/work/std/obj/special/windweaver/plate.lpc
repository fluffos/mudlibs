#include <unique_armour.h>
#include <daemons.h>

int authentic = 0;

#include "armour_set.h"

void create_armour() {
    if (set_unique(object_name(this_object()), UNIQUENESS_FULL, 1, 0)) {
	set_name("windweaver full plate");
	set_short("The Windweaver Full Plate");
	set_type("armour");
	set_id(({ "plate", "full plate", "windweaver full plate", "#windweaver full plate#" }));
	set_long("The Windweaver Full Plate armour is made of enchanted silver.");
	set_ac(5);
	set_weight(10);
	set_value(10000);

	authentic = 1;
	ARMOUR_SET_D->add_armour("windweaver", this_object());
    } else destruct(this_object());
}

