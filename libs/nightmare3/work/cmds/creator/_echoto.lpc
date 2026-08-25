//      /bin/dev/_echoto.c
//      from the Nightmare Mudlib
//      echoes a message to a player
//      created by ????

#include <std.h>
#include <security.h>

inherit DAEMON;

int cmd_echoto(string str) {
    string text;
    object ob;

    if(!str || sscanf(str,"%s %s",str,text) != 2 || !(ob=find_player(str))) {
        notify_fail(str ? "No such player.\n" : "Echoto whom?\n");
        return 0;
    }
    message("environment", text, ob);
    message("my_action","You echo to "+capitalize(str)+": "+text,this_player());
    seteuid(UID_LOG);
    log_file("shouts", geteuid(previous_object())+" (echoto "+str+"): "+text+
      "\n");
    seteuid(getuid());
    return 1;
}

void help() {
    message("help",
      "Syntax: <echoto [player] [message]>\n\n"
      "Sends a message to the player named.  Abuse of this power "
      "can result in serious action from law.", this_player()
    );
}
