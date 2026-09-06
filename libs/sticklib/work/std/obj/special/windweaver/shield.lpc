#include <unique_armour.h>
#include <daemons.h>

int authentic = 0;

#include "armour_set.h"

void create_armour() {
    if (set_unique(object_name(this_object()), UNIQUENESS_FULL, 1, 0)) {
	set_name("windweaver shield");
	set_short("The Windweaver Shield");
	set_type("shield");
	set_id(({ "shield", "windweaver shield", "#windweaver shield#" }));
	set_long("The Windweaver Shield is made of enchanted silver.");
	set_ac(2);
	set_weight(4);
	set_value(6000);

	authentic = 1;
	ARMOUR_SET_D->add_armour("windweaver", this_object());
    } else destruct(this_object());
}

