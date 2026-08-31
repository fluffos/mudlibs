#include <std.h>

inherit ARMOUR;

void create() {
    ::create();
    set_name("mask");
    set_id(({"mask", "ninja mask"}));
    set_short("%^BOLD%^%^BLACK%^N %^WHITE%^i %^BLACK%^n %^WHITE%^j %^BLACK%^a  %^WHITE%^M %^BLACK%^a %^WHITE%^s %^BLACK%^k");
    set_long("A mask that looks cool, but offers no protection.");
    set_type("helmet");
    set_limbs(({"head"}));
}

int query_auto_load() {
  if(this_player()->query_name() == "gob") return 1;
    return 0;
}
