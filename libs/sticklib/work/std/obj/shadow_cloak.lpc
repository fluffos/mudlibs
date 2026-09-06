/* Shadow Cloak (Thieve's Cloak) */

/* Expensive and rare: container/armour */

#include <armour.h>

int max_weight, local_weight;

void
create_armour()
{
    set_name("shadow cloak");
    set_id(({"shadow", "cloak"}));
    set_short("Shadow cloak");
    set_long(
      "This black silk cloak is meant for the people who sneak silently in the \
night. You notice that the cloak has pockets.");
    set_ac(1);
    set_weight(2);
    set_size(({ 120, 120, 0 }));  /* Depth 0: object that can be folded */
    set_type("cloak");
    set_value(800); // Was 2600, too good.
    set_info("It's a genuine Shadow Cloak!");

    max_weight = 3;
}

can_put_and_get() { return 1; }
query_inserted_weight() { return local_weight; }

add_weight(w) {
    if (local_weight + w > max_weight)
	return 0;
    local_weight += w;
    return 1;
}

prevent_insert() {
    if (local_weight > 0) {
	write("You can't when there are things in the " + query_name() + ".\n");
	return 1;
    }
    return 0;
}

set_max_weight(w) { max_weight = w; }
query_max_weight() { return max_weight; }
