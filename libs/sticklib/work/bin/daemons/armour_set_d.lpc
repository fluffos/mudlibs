mapping armour_sets;

void create() {
    armour_sets = ([]);
}

void add_armour(string armour_set, object armour) {
    if (!member(armour_sets, armour_set)) {
	armour_sets += ([ armour_set : ({}) ]);
    }

    armour_sets[armour_set] -= ({ 0 });

    if (member(armour_sets[armour_set], armour) < 0) {
	armour_sets[armour_set] += ({ armour });
    }
}

object *query_armour_set(string armour_set) {
    if (!member(armour_sets, armour_set)) {
	return 0;
    }

    armour_sets[armour_set] -= ({ 0 });

    return armour_sets[armour_set];
}

object remove_armour_sets() {
    armour_sets = ([]);
}

void remove_armour_set(string armour_set) {
    armour_sets -= ([ armour_set ]);
}
