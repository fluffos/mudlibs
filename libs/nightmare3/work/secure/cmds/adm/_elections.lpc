//    /cmds/adm/_elections.c
//    From the Nightmare mudlib
//    Command to start, stop and set date for elections.
//    Original by Descartes of borg.
//    re-written by Kalinash for new voting daemon 040294

#include <std.h>
#include <daemons.h>
#include <security.h>

inherit DAEMON;

int cmd_elections(string drow) {
    string what, date;

    if(!sscanf(drow, "%s %s", what, date))
        return notify_fail("What do you want to do?\n");
    if(what == "start") {
        VOTING_D->start_elections();
        message("shout", "Election Announcement:  Elections have now "
          "begun!", users());
        return 1;
    }
    if(what == "end") {
        VOTING_D->end_elections();
        message("shout", "Election Announcement:  Elections are now over!",
          users());
        return 1;
    }
    if(what == "date") {
        if(!date) return notify_fail("You must give me a date!\n");
        VOTING_D->set_vote_date(date);
        message("my_action", sprintf("The voting start day is now set to "
          ": %s", date), this_player());
        return 1;
    }
    return notify_fail("You did something wrong.\n");
}

void help() {
    message("help", "Usage : elections <start | end | date string date>\n\n"
      "This command is used to start and stop the elections process as well "
      "as allowing you to set the next start date for the elections.",
      this_player());
    return;
}
