#include <treasure.h>
#include "../priest.h"

create_treasure() {
    set_name("charity box");
    set_id("box");
    set_long("It's a small box with a hole on the top of it. You can \
use it to donate money to the church by dropping gold coins into it. \
It seems to be attached to the wall.");
}

init_treasure() {
    add_action("drop_cmd", "drop");
}

status drop_cmd(string arg) {
    string what, where;
    int amount;

    notify_fail("Drop what into where?\n");
    if(!arg || sscanf(arg, "%d %s into %s", amount, what, where) != 3)
	return 0;

    if(what != "gc" && what != "gold coins" && what != "coins")
	return 0;

    if(!id(where)) return 0;
    if(amount < 0) {
	this_player()->tell_me("Donate a negative amount??");
	return 1;
    }
    if(this_player()->query_money() < amount) {
	this_player()->tell_me("You don't have that much money with you.");
	return 1;
    }
    this_player()->tell_me(sprintf("You donated %d gc to the \
priest guild.", amount));
    this_player()->add_money(-amount);
    CASH_D->add_money(amount, this_player()->query_real_name());
    return 1;
}

status get() { return 0; }
status drop() { return 0; }
