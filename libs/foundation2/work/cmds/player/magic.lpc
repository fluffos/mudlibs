/*  a magic command to interface beek's magic system */

#include <lib.h>

inherit LIB_DAEMON;

mixed cmd(string str) {
    if( present("magic", this_player()) ) {
	message("system", "You are already set to play!", this_player());
	return 1;
    }
    if( (int)new("/realms/b/beek/magic")->eventMove(this_player()) ) {
	message("system", "You are ready to play magic.", this_player());
	message("other_action", (string)this_player()->GetName() +
		" is ready to play magic.", environment(this_player()),
		this_player());
	return 1;
    }
    return "Error in loading magic object.";
}

void help() {
    message("help", "Syntax: <magic>\n\n"
	    "Starts you with magic.  From that point, type \"magichelp\".",
	    this_player());
}
