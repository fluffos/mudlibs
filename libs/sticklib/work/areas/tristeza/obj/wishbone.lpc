/* wishbone of a duck - an important spell component... */

#include <treasure.h>

void
create_treasure()
{
    set_name("wishbone");
    set_id(({ "bone", "wishbone of duck", "duck wishbone" }));
    set_weight(1);
    set_short("wishbone of a duck");
    set_long("How about making a wish?");
    set_value(0);
}

init() {
    add_action("wish","wish");
}

wish(arg) {
    write("You wish " + arg + ".\n");
    return 1;
}
