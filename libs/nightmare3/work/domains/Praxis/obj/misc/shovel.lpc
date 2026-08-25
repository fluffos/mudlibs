//	shovel.c created by Descartes 921004
//	it digs in rooms that look for shovels when digging is done

#include <std.h>

inherit OBJECT;

void init() {
    ::init();
    add_action("dig", "dig");
}

void create() {
    ::create();
    set_id( ({ "shovel" }) );
    set_name("shovel");
    set_short( "a shovel");
    set_long( "You might be able to dig with this in the right soil.");
    set_mass(100);    set_value( 18);

}

int dig(string str) {
    notify_fail("The shovel can't quite manage the soil here.\n");
    return 0;
}
