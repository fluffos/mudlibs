#include <std.h>
inherit BAG;
void create() {
    ::create();
    set_name("crater");
    set_id( ({ "crater", "crate", "a crate", "a crater", "pit" }) );
    set_short("%^BOLD%^%^BLACK%^a crater%^RESET%^");
    set_long("This large crater is used as a place where players can discard unwanted items so that less fortunate souls might scavenge them and put them to better use. \n");
    set_mass(10000000); 
    set_max_internal_encumbrance(1000000);
    set_value(0);
    set_prevent_get("How can one pick up a crater?");
}

int is_bag() {return 0;}

varargs int receive_objects(object ob) { return 1; }
