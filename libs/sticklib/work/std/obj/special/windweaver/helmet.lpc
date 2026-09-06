#include <unique_armour.h>
#include <daemons.h>

int authentic = 0;

#include "armour_set.h"

void create_armour() {
    if (set_unique(object_name(this_object()), UNIQUENESS_FULL, 1, 0)) {
	set_name("windweaver helmet");
	set_short("The Windweaver Helmet");
	set_type("helmet");
	set_id(({ "helmet", "windweaver helmet", "#windweaver helmet#" }));
	set_long("The Windweaver Helmet is made of enchanted silver.");
	set_ac(2);
	set_weight(4);
	set_value(4000);

	authentic = 1;
	ARMOUR_SET_D->add_armour("windweaver", this_object());
    } else destruct(this_object());
}

