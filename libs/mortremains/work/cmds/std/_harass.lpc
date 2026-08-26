// _harass.c
//
// this command is for the purpose of turning on the harassment logging
// mechanism, so that when a user is being harassed (s)he is able to attempt
// to obtain some evidence of it.
//
// this implementation was done by Buddha@TMI-2 on 930831
// 'tis a part of the TMI-2 distribution mudlib.

// for reference, this depends on a hook in /std/body::receive_message() 
// and the "harass" property being locked in /std/user::create()

#include <mudlib.h>
#include <logs.h>

inherit DAEMON;

#define USAGE "Syntax: harass <minutes>\n"

int cmd_harass(string timestr) {
	int mins;
	int fs ;

	if (!timestr || !sscanf(timestr, "%d", mins)) {
		notify_fail(USAGE);
		return 0;
	}
	fs = file_size(HARASS_DIR);
	if (fs>0) {
           notify_fail ("Can't log as the file "+ HARASS_DIR +
      "exists. Notifyan admin immediately.\n") ;
	    return 0 ;
	}
	if (fs==0) {
           rm(HARASS_DIR);
	}
	if (fs>-2) {
            mkdir(HARASS_DIR);
	}
       log_file(HARASS_DIR+"/"+geteuid(this_player()),
		"Harassment Log started: " + ctime(time()) +
		"\n========================================\n");
	write("Harassment Log started at " + ctime(time()) +
		".\nEverything you see for the next " + mins +
		" minutes will be logged.\n");
	this_player()->set("harass", time() + 60 * mins);
	return 1;
}

string help() {
	return(USAGE+"\n"
	"If you are being sexually harassed, there is something you can do\n"
	"to help yourself.  This command will automatically turn a\n"
	"log on, that will log everything that you see while it is on.  It\n"
	"will turn off after the number of minutes you have given have\n"
	"elapsed.  When you turn the log on, the time is also logged,\n"
	"and when it turns off the time is noted once again.\n");
}

