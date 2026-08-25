/*    /cmds/mortal/_harass.c
 *    from Nightmare IV
 *    command to allow a person to log their session for law
 *    created by Descartes of Borg at the request of Forlock 940410
 */

#include <std.h>

inherit DAEMON;

int cmd_harass(string str) {
    if(str == "off") {
        if(!((int)this_player()->query_log_harass()))
          return notify_fail("You are not logging!\n");
        message("system", "You are no longer logging your session.",
          this_player());
        message("system", sprintf("Log ended at %s.", ctime(time())), this_player());
        this_player()->set_log_harass(0);
        return 1;
    }
    if(str != "on") return notify_fail("Syntax: <harass [on|off]>\n");
    if((int)this_player()->query_log_harass())
      return notify_fail("You are already logging your session for law.\n");
    this_player()->set_log_harass(1);
    message("system", "You are now logging your MUD session for law.",
      this_player());
    message("system", sprintf("Log started at %s.", ctime(time())), this_player());
    return 1;
}

void help() {
    message("help", "Syntax: <harass [on|off]>\n\n"
      "If you turn it on, then everything you see on the MUD "
      "gets logged to a file for the law department to review.  "
      "This command is useful to gain evidence of someone harassing "
      "you.  To turn it off (which you should do the minute you are "
      "done), type \"harass off\".  If you log for too long, "
      "you will lose the stuff from the beginning after the log "
      "grows too long.  So only log what you need.", this_player());
}
