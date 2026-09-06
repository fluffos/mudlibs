#include <treasure.h>
#include "../priest.h"

string
show_list() {
    if(!IS_PRIEST(this_player()))
	return "You don't understand the language.";
    return BOOKKEEPER->top_alc_list();
}

void
create_treasure() {
    set_name("top board");
    set_id("board");
    set_long(#'show_list);
}

status get() { return 0; }
status drop() { return 1; }
