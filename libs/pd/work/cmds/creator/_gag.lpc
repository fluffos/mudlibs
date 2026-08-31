// Made by Inferno to silence people
#include <std.h>
inherit DAEMON;

int cmd_gag(string str) {
    object ob;
    string who, timestr;
    int time = 0;
    mapping units = ([
      "sec" : 1, "min" : 60, "hour" : 60*60, "day" : 60*60*24, "week" : 60*60*24*7, "month" : 60*60*24*7*4,
    ]);

    if(!str) {
	notify_fail("Gag who?\n");
	return 0;
    }
    if (sscanf(str, "%s %s", who, timestr) != 2) who = str;
    else {
      int num;
      foreach (string unit, int value in units) {
        if (sscanf(timestr, "%*s%d "+unit+"%*s", num) == 3) time += num*value;
        else if (sscanf(timestr, "%*s%d "+unit+"s%*s", num) == 3) time += num*value;
      }
    }

    ob = find_living(who);
    if (!ob) {
	notify_fail("Could not find: "+str+"!");
	return 0;
    }
    if(!wizardp(this_player())) {
	notify_fail("You are not permitted to do that.\n");
	return 0;
    }
    if (ob->query_property("gagged")) {
	notify_fail("It is already so.");
	return 0;
    }
    ob->set_property("gagged", 1);
    write("Player gagged.");
    if (time) {
      ob->set_property("gagtime", time);
      write("Duration: "+timestr+" ("+time+" secs)");
    }
      
    return 1;
}

void help() {
  message("help",
    "Syntax: <gag [who] [time]>\n\n"
    "Gags a player. Time is optional, some examples include:\n"
    "  5 mins\n"
    "  5 hours 20 mins\n"
    "  3 days 15 hours\n"
    "  2 weeks\n\n"
    "Player login time will count towards being gagged as long as they are "
    "not idle longer than 7 minutes.",
    this_player() );
}
