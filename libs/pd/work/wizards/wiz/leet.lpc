#include <std.h>
inherit ARMOUR;

void create(){
    ::create();
    set_name("h0h0 hat");
    set_properties(([ "no steal":1, "magic item":({"squishie"})]));
    set_short("%^BOLD%^%^WHITE%^h0h0 hat%^CYAN%^!%^RESET%^");
    set_long("This is a furry little white hat.");
    set_id(({ "hat", "h0h0 hat" }));
    set_mass(-1);
    set_type("hat");
    set_value(0);
    set_limbs(({ "head" }));
    set_ac(1);
}

int query_auto_load()
{
    if (member_array(this_player()->query_name(), ({ "wiz", "noa" })) != -1)
        return 1;
    return 0;
}
