#include <std.h>

inherit ARMOUR;

void create() {
::create();
    set_name("Dark Wings");
    set_short("%^BOLD%^%^BLACK%^Dark %^WHITE%^W%^RESET%^%^WHITE%^i%^BOLD%^ngs%^RESET%^");
    set_long("Darkness consumes these wings.");
    set_id(({"wings", "dark wings"}));
    set_ac(1);
    set_mass(15);
   set_curr_value("gold", 150);
   set_type("wing armour");
    set_limbs(({"left wing", "right wing"}));
}

int query_auto_load() { 
    if(this_player()->query_guild() == "forsaken") return 1;

}
