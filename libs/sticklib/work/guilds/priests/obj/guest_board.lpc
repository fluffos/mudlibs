#include <treasure.h>
#include "../priest.h"

string
show_list() {
    if(!IS_PRIEST(this_player()))
	return "You don't understand the writing.";
    if(this_player()->query_level() < 10)
	return "You are still too young to understand the writing.";

    return GUEST_D->query_guests();
}

void
create_treasure() {
    set_name("guest board");
    set_id("board");
    set_long(#'show_list);
}

status get() { return 0; }
status drop() { return 1; }
