#include <std.h>
inherit OBJECT;
 
void create() {
::create();
    set_id(({"stone", "sunstone"}));
    set_name("sunstone");
    set_short("%^YELLOW%^Sunstone%^RESET%^");
    set_long("This stone has been blessed by the altar of the sun, and is quite rare.");
    set_properties(([ "no steal" : 1 ]));
    set_mass(1);
    set_curr_value("gold", 0);
}

int drop() { return 1; }

int get() { return 1; }

int give() { return 1; }

int bury() { return 1; }
