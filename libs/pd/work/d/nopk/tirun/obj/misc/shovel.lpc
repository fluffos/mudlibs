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
    set("id", ({ "shovel" }) );
    set_name("shovel");
    set("short", "a shovel");
    set("long", "You might be able to dig with this in the right soil.");
    set_weight(15);
    set_curr_value("gold", 5);
    set_property("magic item", ({"dig"}) );
}

int dig(string str) {
    notify_fail("The shovel can't quite manage the soil here.\n");
    return 0;
}
