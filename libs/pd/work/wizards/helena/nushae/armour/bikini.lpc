#include <std.h>

inherit ARMOUR;

void create() {
  ::create();
    set_name("bikini");
    set_short("%^BOLD%^%^MAGENTA%^SeaShell%^RESET%^ Bikini");
    set_id(({ "bikini" }));
    set_long("A %^BOLD%^%^MAGENTA%^SeaShell%^RESET%^ bikini worn by the mermaids of %^CYAN%^Nu%^MAGENTA%^Sh%^CYAN%^ae%^RESET%^.");
    set_weight(4);
    set_curr_value("gold", 30-random(15));
    set_type("tunic");
    set_limbs(({ "torso" }));
    set_ac(1);
}

int query_auto_load(){
    if (this_player()->query_level() > 10) return 1;
    if (this_player()->query_cap_name()=="sasayaki") return 0;
    return 0;
}
