#include <std.h>
inherit WEAPON;

void create() {
    ::create();
    set_id(({"wakizashi", "bomos wakizashi", "bomo"}));
    set_name("wakizashi");
    set_short("Bomo's Wakizashi");
    set_long("This wakizashi is of slightly lesser quality then those generally found in the lands of Minori. It is undecorated and very plain, with the handle and blade showing signs of age and wear. Despite that, this wakizashi is well kept for and apparently well loved. The hilt bears the symbol of the Tamada family in Minori, and they may appreciate it's return. The people of Minori believe that the spirit of the wielder is kept in the blade of the wakizashi, so the Tamada family would probably appreciate it if you treated it with the same respect you'd pay Bomo.");
    set_mass(19);
    set_value(700);
    set_wc(2);
    set_type("blade");
    set_hands(1);
    set_unwield((:call_other, this_object(),"unwield":));
    set_wield((:call_other, this_object(),"wield":));
}

int wield() {

    write("This wakizashi refuses to be wielded by you. It, somehow, manages to avoid your grasp.");

    return 0;

}

int unwield() {

    write("Eh? WTF? You wielded this? Bug. Tell Sakura or Stormbringer. Man, this is some messed up stuff right here.");

    return 1;
}
