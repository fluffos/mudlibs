//      _earmuffs.c
//      An immortal way to block shouts for use with Nightmare Channels
//      created by Descartes of Borg 31 October 1992 (boo)

#include <std.h>

inherit DAEMON;

#include <daemons.h>

int cmd_earmuffs(string str) {
    if(str) {
        notify_fail("The earmuffs command does not accept an argument.\n");
        return 0;
    }
    this_player()->set_blocked("shout");
    return 1;
}

void help() {
    write("Syntax: <earmuffs>\n\n"+
        "Toggles you between blocking and accepting shouts.\n");
}
