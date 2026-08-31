#include <std.h>

inherit ARMOUR;

void create() {
  ::create();
    set_name("hat");
    set_id(({ "hat", "dunce hat" }));
    set_short("%^BOLD%^%^GREEN%^A Dunce Hat%^RESET%^");
    set_long("This hat is made out of common %^BOLD%^%^GREEN%^seaweed%^RESET%^ found in %^CYAN%^Nu%^MAGENTA%^Sh%^CYAN%^ae%^RESET%^.");
    set_weight(2);
    set_ac(1);
    set_type("helmet");
    set_limbs(({ "head" }));
}

int query_auto_load() {
    if (this_player()->query_level() >=10) return 1;
}
