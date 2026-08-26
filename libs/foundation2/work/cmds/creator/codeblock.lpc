//      codeblock.c
//      created by Descartes of Borg 31 October 1992


#include <lib.h>

inherit LIB_DAEMON;

#define CHANNELS "bin/daemon/channels"

int cmd() {
    this_player()->SetBlocked("all");
    if(this_player()->GetBlocked("all")) write("Codeblock on.\n");
    else write("Codeblock off.\n");
    return 1;
}

void help() {
    write("Syntax: <codeblock>\n\n"+
        "Toggles between blocking and not blocking all remote communications.\n");
}
