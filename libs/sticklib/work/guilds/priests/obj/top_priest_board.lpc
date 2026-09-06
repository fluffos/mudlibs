#include <treasure.h>
#include "../priest.h"

string
show_list() {
    if((!IS_PRIEST(this_player())) && (!this_player()->query_coder_level()))
	return "The text on the board is written in some ancient script \
you can't understand.";
    return BOOKKEEPER->top_spell_list();
}

void
create_treasure() {
    set_name("top board");
    set_id("board");
    set_long(#'show_list);
}

status get() { return 0; }
status drop() { return 1; }

status read_cmd(string what) {
    this_player()->tell_me(show_list());
    return 1;
}
