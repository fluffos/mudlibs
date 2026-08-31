#include <std.h>
inherit WEAPON;

void create() {
::create();
    set_name("Jagged Sword");
    set_short("%^BLACK%^%^BOLD%^Ja%^WHITE%^gg%^BLACK%^ed %^WHITE%^Sw%^BLACK%^ord");
    set_long("%^BOLD%^%^BLACK%^         ^ \n" 
        "        / \\ \n"
        "        | | \n"
        "        / / \n"
        "        \\ \\ \n"
        "        | | \n"
        "        \\ \\ \n"
        "        / / \n"
        "        | | \n"
        "     [==%^RED%^+++%^BOLD%^%^BLACK%^==] \n"
        "        [+] \n"
        "        [+] \n"
        "        [+]\n");
    set_id(({"jagged sword", "sword"}));
    set_mass(16);
    set_value(550);
    set_type("blade");
    set_hands(1);
    set_wc(14);
    set_ac(1);
}
int query_auto_load() { if (this_player()->query_level() > 19) return 1; }
