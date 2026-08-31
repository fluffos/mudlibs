#include <std.h>

inherit ARMOUR;

void create() {
  ::create();
    set_name("bikini");
    set_short("Luti's %^MAGENTA%^Coral%^RESET%^ Bikini");
    set_id(({ "bikini", "coral bikini" }));
    set_long("A %^BOLD%^%^MAGENTA%^SeaShell%^RESET%^ bikini worn by the Princess of all %^CYAN%^Nu%^MAGENTA%^Sh%^CYAN%^ae%^RESET%^, Princess Luti. Made from coral, it is extremely fragile.");
    set_weight(3);
    set_curr_value("gold", 60-random(10));
    set_type("tunic");
    set_limbs(({ "torso" }));
    set_ac(1);
}

int query_auto_load(){
    if (this_player()->query_level() > 15) return 1;
    if (this_player()->query_cap_name()=="sasayaki") return 0;
    return 0;
}
