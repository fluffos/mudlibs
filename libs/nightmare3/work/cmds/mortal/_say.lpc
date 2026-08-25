//      /bin/user/_say.c
//      from the Nightmare Mudlib
//      the say command
//      created by Descartes of Borg 930818

#include <std.h>

inherit DAEMON;

int cmd_say(string str) {
    if(this_player()->query_ghost()) {
        message("talk", "You howl pitifully.", this_player());
        message("talk", "You hear a pitiful howl.", environment(this_player()),
          ({ this_player() }));
        return 1;
    }
    if(!str || str == "") {
        notify_fail("You mutter to yourself.\n");
        return 0;
    }
    say(sprintf("%s says: %s", (string)previous_object()->query_cap_name(),
      str));
    write(sprintf("You say: %s", str));
    return 1;
}

void help() {
    write("Syntax: <say [message]>\n\n"
      "Sends out a message to everyone in the room notifying them that "
      "you said it."
      "\n\nSee also: tell, whisper, shout, yell, class, emote"
    );
}
