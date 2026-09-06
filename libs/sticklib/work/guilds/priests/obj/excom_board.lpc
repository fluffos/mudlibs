#include <treasure.h>
#include "../priest.h"

string
show_list() {
    if(!IS_PRIEST(this_player()))
	return "You don't understand the writing.";
    if(this_player()->query_level() < 10)
	return "You are still too young to understand the writing.";

    return EXCOM_D->excoms();
}

void
create_treasure() {
    set_name("excom board");
    set_id("board");
    set_long(#'show_list);
}

status get() { return 0; }
status drop() { return 1; }
