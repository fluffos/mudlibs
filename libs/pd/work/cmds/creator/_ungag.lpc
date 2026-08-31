#include <std.h>
inherit DAEMON;

int cmd_ungag(string str) {
    object ob;

    if(!str) {
        notify_fail("ungag what?\n");
        return 0;
    }
    ob = find_living(str);
    if (!ob) {
        notify_fail("Could not find: "+str+"!");
        return 0;
    }
    if(!wizardp(this_player())) {
        notify_fail("You are not permitted to do that.\n");
        return 0;
    }
    ob->remove_property("gagged");
    ob->remove_property("gagtime");
    write("Player ungagged.");
    return 1;
}

void help() {
  message("help",
    "Syntax: <ungag [who]>\n\n"
    "Ungags a player so he can talk again.",
    this_player() );
}
