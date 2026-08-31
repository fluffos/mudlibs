#include <std.h>
inherit BAG;
void create() {
    ::create();
    set_name("pit");
    set_id( ({ "pit", "a pit" }) );
    set_short("a pit");
    set_long("This large pit is used as a place where players can discard unwanted "
      "items so that less fortunate souls might scavenge them and put them to better use. \n");
    set_mass(10000000); // No one's picking this thing up.
    set_max_internal_encumbrance(1000000);
    set_value(0);
    set_prevent_get("The pit's foundations reaches deep underground.");
    set_short_more( ({}) );
}

int is_bag() {return 0;}

varargs int receive_objects(object ob) { return 1; }
