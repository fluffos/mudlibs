#include "../priest.h"
#include <key.h>

create_key() {
    set_type("decorative golden");
    set_code("chopin_was_here");
}

void destruct_me(object pl) {
    if(pl) pl->tell_me("Oh no! The key broke.");
    destruct(this_object());
}

string query_code() {
    if(!random(3)) call_out(#'destruct_me, 2, this_player());
    return ::query_code();
}

init() {
    if(interactive(this_player()) && !this_player()->query_coder_level())
	write_file(PRIEST_LOG_DIR "shop_key", sprintf("%s %s\n",
	    ctime(time()), this_player()->query_real_name()));
}
