#include <unique_armour.h>
#include <daemons.h>

int authentic = 0;

#include "armour_set.h"

void create_armour() {
    if (set_unique(object_name(this_object()), UNIQUENESS_FULL, 1, 0)) {
	set_name("windweaver leggings");
	set_short("The Windweaver Leggings");
	set_type("leggings");
	set_id(({ "leggings", "windweaver leggings", "#windweaver leggings#" }));
	set_long("The Windweaver Leggings is made of enchanted silver.");
	set_ac(1);
	set_weight(1);
	set_value(8000);

	authentic = 1;
	ARMOUR_SET_D->add_armour("windweaver", this_object());
    } else destruct(this_object());
}

