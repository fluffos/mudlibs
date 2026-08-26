
#include <npc/transport.h>

inherit "/obj/monster/transport/horse_base";

void setup() {
    basic_setup("horse", 50, 1 + random( 2 ) );
    set_name("horse");
    add_adjective("war");
    set_long("This horse has an air of calmness about it, it just stands "
        "there and looks very calm.\n");

    set_inside_long("You can see the horse's mane and it looking calmly "
        "into the distance.\n");

    // 100 platinum coins in value.
    set_value( 6000 * 100 );
    set_maximum_speed(RIDE_GALLOP);
    set_transport_type("horse");
    set_default_mount_difficulty(100);
    set_default_direction_difficulty(20);
    set_transport_speed(3);
    set_maximum_exhaustion(600);
    adjust_bonus_str(5);
    adjust_bonus_con(5);

} /* setup() */
