// Showemail command.
// Hides your email addy from non-players

#include <priv.h>

int cmd_showemail() {
    seteuid(getuid());

    if (!TP->query("email_visible")) {
	TP->set("email_visible", 1, READ_ONLY);
	write("Your email address is now public.\n");
    } else {
	TP->set("email_visible", 0, READ_ONLY);
	write("Your email address is now hidden.\n");
    }

    return 1;    
}

/* EOF */
