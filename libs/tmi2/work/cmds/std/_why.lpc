// This file is part of the TMI distribution mudlib.
// Please include this header if you use this code.
// Written by Robocoder, 94-04-30

#include <config.h>
#include <mudlib.h>
#include <daemons.h>

#define SYNTAX "Syntax: why [-q]"

int cmd_why(string arg) {
    string reason;

    seteuid(getuid());
    if (!((int)SHUTDOWN_D->query_shutdown())) {
        if (arg != "-q")
            write("There is no shutdown presently scheduled.\n");
    } else {
        reason = SHUTDOWN_D->query_reason();
        if (reason)
            write(wrap(sprintf("A shutdown is in progress ``%s''\n", reason)));
    }
    return 1;
}

int help() {
    write( SYNTAX "\n" @ENDTEXT
If a shutdown is imminent, this command returns the reason for scheduling
the shutdown.  Similarly, "why" will report the absence of a shutdown in
progress, unless the -q option is specified.
ENDTEXT
    );
    return 1;
}
