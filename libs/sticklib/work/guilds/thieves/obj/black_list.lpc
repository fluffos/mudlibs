inherit "basic/id";

#include "dirs.h"

#define AL GDIR + "ATTACKLOG"

reset(arg) {
    set_name("black list");
    set_id(({ "list" }));

    if (!environment())
	move_object(this_object(), GDIR + "rooms/guild");
}

init() {
    add_action("read", "read");
}

read(arg) {
    if (id(arg)) { long(0); return 1; }
    return 0;
}

long(arg) {

    tail(AL);
}

log_attack(str) {
    if (str) write_file("ATTACKLOG",str);
}
