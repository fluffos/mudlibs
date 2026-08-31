#include <std.h>
#include <arlon2.h>

inherit BAG;
void create() {
    ::create();
    set_id( ({"bag", "shopping bag", "shoppingbag"}) );
    set_name("a small shopping bag");
    set("short", "a small shopping bag");
    set_weight(5);
    set("long", "This small shopping bag is made out of a burlap sack with a small handle on it.  It seems to have been enchanted ");
    set_curr_value("gold", 50);
    set_max_internal_encumbrance(300+random(200));
}
int query_auto_load() { return 1; }
