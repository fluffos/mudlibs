//      /bin/dev/_echoall.c
//      from the Nightmare Mudlib
//      echos to everyone on the mud
//      created by ????

#include <std.h>

inherit DAEMON;

int cmd_echoall(string str) {
    if(!str) {
        notify_fail("Echoall what?\n");
        return 0;
    }
    message("shout", str, users());
    return 1;
}

void help() {
    message("help",
      "Syntax: <echoall [message]>\n\n"
      "Sends the message to all users in the game.  Abuse of this "
      "power can result in serious action from law.", this_player()
    );
}
