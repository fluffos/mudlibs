#include <std.h>

#include <caves.h>

inherit WEAPON;

void create() {
::create();
    set_name("jeweld longsword");
    set_short("%^BOLD%^%^MAGENTA%^J%^GREEN%^e%^BLUE%^w%^MAGENTA%^e%^BLUE%^l%^YELLOW%^d%^BLACK%^ Longsword%^RESET%^");
    set_long("Jems and other foreign rubys are bound to this sword.");
    set_id(({"sword", "longsword"}));
    set_mass(100);
    set_value(2000);
    set_type("blade");
    set_hands(1);
    set_wc(20);
    set_ac(1);
}

int query_auto_load() { 
    if (this_player() ->query_level() > 79) return 1;

}
