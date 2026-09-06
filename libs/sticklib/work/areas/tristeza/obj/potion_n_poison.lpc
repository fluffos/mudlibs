/* Potion of Neutralize Poison */
#include <drink.h>
#include <conditions.h>

#define TP this_player()
#define POISON_D "/guilds/thieves/poison_d"

void create_drink() {
    set_name("icky green potion");
    set_id(({ "icky green", "icky", "green", "potion" }));
    set_short(capitalize(query_name()));
    set_long("The label on this potion says: \"Ye Olde Potion of "+
      "Neutralizing Poison\".\n");
    set_info("It is just the stuff that the label says.\n");
    set_empty_container("bottle");
    set_drinker_mess("Glug-glug-glug...");
    set_value(620);
    set_strength(1);
    set_soft(1);
}

extra_drink() {
    int x;

    x = 0;
    if (TP->query_condition(C_POISONED) > 0) {
	TP->set_condition(C_POISONED, 0);
	x++;
    }
    if (POISON_D->is_poisoned(TP)) {
	POISON_D->remove_poisoned_living(TP);
	x++;
    }

    if (!x)
	TP->tell_me("\nNothing happens!");
}
