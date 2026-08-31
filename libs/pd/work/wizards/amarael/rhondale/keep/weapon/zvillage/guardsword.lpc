// Amarael

#include <std.h>
inherit WEAPON;
 
void create() {
::create();
    set_id(({"sword", "longsword", "steel sword"}));
    set_name("longsword");
    set_short("Steel Sword");
    set_long("This sword has been crafted from forged steel and is quite durable.");
    set_mass(15);
    set_curr_value("gold", 140);
    set_wc(11);
    set_type("blade");
    set_hands(1);
}

int query_auto_load() {
    if (this_player()->query_level() > 33) return 1; 
}
