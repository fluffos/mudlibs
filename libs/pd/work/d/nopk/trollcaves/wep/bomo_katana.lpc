#include <std.h>
inherit WEAPON;

void create() {
    ::create();
    set_id(({"katana", "bomos katana", "bomo"}));
    set_name("katana");
    set_short("Bomo's Katana");
    set_long("This katana is broken in two, the blade snapped off just above the handle. Clearly, this is because the of slightly lesser quality of the sword then those generally found in the lands of Minori. It is undecorated and very plain, with the handle and blade showing signs of age and wear. In addition, the blade is somewhat more grainy then would be expected from folded steel. This katana appears to be freshly forged, and could not be more then a few days old. The hilt bears the symbol of the Tamada family in Minori.");
    set_mass(29);
    set_value(10);
    set_wc(1);
    set_type("blade");
    set_hands(2);
    set_unwield((:call_other, this_object(),"unwield":));
    set_wield((:call_other, this_object(),"wield":));
}

int wield() {

    write("This sword is broken and cannot be wielded.");

    return 0;

}

int unwield() {

    write("Eh? WTF? You wielded this? Bug. Tell Sakura or Stormbringer. Man, this is some messed up stuff right here.");

    return 1;
}
