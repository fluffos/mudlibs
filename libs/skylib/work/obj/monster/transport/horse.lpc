
#include <npc/transport.h>

inherit "/obj/monster/transport/horse_base";

void setup() {
    basic_setup("horse", 20, 1 + random( 2 ) );
    set_name("horse");
    set_long("A nice dark dashing horse, it looks strong and happy as its "
        "brown eyes stare into your own.\n");

    set_inside_long("You can see the horses hair and ear's flicking at the "
        "slightest sounds.  The smell of horse is quite strong.\n");

    // 50 platinum coins in value.
    set_value( 6000 * 50 );
    set_maximum_speed(RIDE_GALLOP);
    set_transport_type("horse");
    set_default_mount_difficulty(100);
    set_default_direction_difficulty(100);
    set_transport_speed(2);
    set_maximum_exhaustion(300);

} /* setup() */
