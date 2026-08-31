#include <std.h>
inherit WEAPON;

void create() {
    ::create();
    set_id(({"dagger", "rusted dagger"}));
    set_name("dagger");
    set_short("Rusted Dagger");
    set_long("This was probably your standard dagger once, but it has since been degraded by rust and corrosion that it is barely more then a lump of metal.");
    set_mass(5);
    set_value(5);
    set_wc(1);           
    set_type("knife");
    set_hands(1);
    set_unwield((:call_other, this_object(),"unwield":));
    set_wield((:call_other, this_object(),"wield":));
}

int wield() {

    write("You gingerly take hold of the rusted dagger.");
    return 1;
}

int unwield() {

    write("You feel a bit safer now that the rusted dagger isn't in your hand.");
    return 1;
}
