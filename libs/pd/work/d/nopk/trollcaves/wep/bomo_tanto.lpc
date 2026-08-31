#include <std.h>
inherit WEAPON;

void create() {
    ::create();
    set_id(({"tanto", "bomos tanto", "bomo"}));
    set_name("tanto");
    set_short("Bomo's Tanto");
    set_long("This tanto is of slightly lesser quality then those generally found in the lands of Minori. It is undecorated and very plain, with the handle and blade showing signs of age and wear. Despite that, this dagger is well kept for and apparently well loved. The hilt bears the symbol of the Tamada family in Minori, and they may appreciate it's return.");
    set_mass(19);
    set_value(700);
    set_wc(8);
    set_type("knife");
    set_hands(1);
    set_unwield((:call_other, this_object(),"unwield":));
    set_wield((:call_other, this_object(),"wield":));
}

int wield() {

    write("The Tanto slips easily into your hand.");

    return 1;

}

int unwield() {

    write("You slip the tanto back into it's sheath.");

    return 1;
}
