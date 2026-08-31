#include <std.h>
inherit WEAPON;

void create() {
    ::create();
    set_id(({"dagger", "rusted", "rusted dagger", "broken dagger"}));
    set_name("rusted dagger");
    set_short("Rusted Dagger");
    set_long("\n"
      "         /( \n"
      "        //\\\\ \n"
      "        |||| \n"
      "        |||( \n"
      "        |||| \n"
      "        |||| \n"
      "         >|| \n"
      "        )||| \n"
      "        |||| \n"
      "        |||| \n"
      "        |||< \n"
      "        |||| /\\ \n"
      "      .\\'  '/ / \n"
      "      \\ \\\\// / \n"
      "       '.  .' \n"
      "         || \n"
      "         || \n"
      "         || \n"
      "         || \n"
      "	 ~ \n"
      "\n"
      "This weapon is in bad shape. It's pommel has been completely broken off, there are many chips and nicks out of the blade, and it is covered in rust.");
    set_mass(6);
    set_value(random(10)+3);
    set_wc(3);
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

    write("You feel somewhat glad to have the rusted weapon out of your hands. You could have gotten an infection.");

    return 1;
}
