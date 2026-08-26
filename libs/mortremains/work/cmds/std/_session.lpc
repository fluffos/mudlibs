/*
**  Cyanide created 21 Jan 98.
**  For players who like session messages, to go along with
**  Cy's new finger daemon.  ;)
** (04-06-98) Chronos adds a help function and fixed an embarassing typo.
*/

#include <mudlib.h>

int cmd_session (string str) {

    if (wizardp(TP)) {
        write(wrap("Immortals do not use session messages.\nInstead, "+
          "put a \".plan\" file in your home directory."));
        TP->delete("session");
        return 1;
    }

    if (!str) {
        str = TP->query("session");
        if (!str) {
            write("You have no session currently set.\n");
        } else {
            write("Your session is currently:\n"+str+"\n");
        }
        return 1;
    }

    if (strlen(str)>300) {
        write("Your session cannot be any longer than 300 characters.\n");
        return 1;
    }
    
    TP->set("session", str);
    return 1;
}

string help() {
  return @ENDHELP
Usage: session [<session_message>]

This command allows you to set a "session message", which is viewable to
all through the finger command.

See also: finger, chfn
ENDHELP
  ;
}
/* EOF */
