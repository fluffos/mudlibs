//      /bin/dev/_rwho.c
//      from the Nightmare Mudlib
//      a udp remote who command
//      created by Descartes of Borg 930805

#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_rwho(string str) {
    if(!str) return 0;
    if(!NETWORK_D->query_mud_info(str) &&
      !NETWORK_D->query_mud_info(str = capitalize(str))) {
        notify_fail("That mud is not available via rwho.\n");
        return 0;
    }
    SERVICES_D->send_rwho_q(str);
    write("Request for rwho info sent to "+str+".\n");
    return 1;
}

void help() {
    write("Syntax: <rwho [mud]>\n\n"
      "Gives you a who list in abbreviated form from a mud on the\n"
      "global network following the CD protocols for intermud communication.\n"
      "The information given by the who varies from mud to mud.\n"
    );
}
