#include <config.h>

int main (string arg) {
    object ob;
    object dest;

    if (!arg) arg = this_player()->query_name();

    dest = find_object(file_name(this_player()));
    if (file_size(PLAYER_DIR+arg[0..0]+"/"+arg+".o") > -1) {
	ob = new("/system/player");
	if (exec (ob, this_player())) {
	    ob->setup(arg);
	    message("standard", "Transfer complete.\n", ob);
	    destruct (dest);
	    return 1;
	}
	else {
	    message("standard", "Permission denied.\n", this_player());
	    return 1;
	}
    }
    message("standard", "No such person exists.\n", this_player());
    return 1;
}
