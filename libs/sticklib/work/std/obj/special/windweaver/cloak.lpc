#include <unique_armour.h>
#include <daemons.h>

int authentic = 0;

#include "armour_set.h"

void create_armour() {
    if (set_unique(object_name(this_object()), UNIQUENESS_FULL, 1, 0)) {
	set_name("windweaver cloak");
	set_short("The Windweaver Cloak");
	set_type("cloak");
	set_id(({ "cloak", "windweaver cloak", "#windweaver cloak#" }));
	set_long("The Windweaver Cloak is woven of enchanted silver rings.");
	set_ac(2);
	set_weight(3);
	set_value(10000);

	authentic = 1;
	ARMOUR_SET_D->add_armour("windweaver", this_object());
    } else destruct(this_object());
}

