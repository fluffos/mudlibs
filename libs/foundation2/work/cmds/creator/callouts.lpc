/*    /cmds/creator/callouts.c
 *    from the Nightmare IV LPC Library
 *    lists all callouts pending
 *    created by Descartes of Borg 950514
 */

#include <lib.h>

inherit LIB_DAEMON;

mixed cmd(string args) {
    mixed *coi;
    string tmp;
    int i, maxi;

    coi = call_out_info();
    if( !sizeof(coi) ) {
	message("system", "No pending callouts.", this_player());
	return 1;
    }
    tmp = sprintf("%:-30s %:-15s %:-5s %s\n", "Object", "Function", 
		  "Delay", "Args");
    tmp += "--------------------------------------------------"
      "-------------------------\n";
    for(i=0, maxi = sizeof(coi); i<maxi; i++) {
	if( sizeof(coi[i]) != 4 ) {
	    tmp += sprintf("Error in element %O\n", coi[i]);
	    continue;
	}
	tmp += sprintf("%:-30s %:-15s %:-5s %O\n",
		       identify(coi[i][0]), identify(coi[i][1]), 
		       identify(coi[i][2]), coi[i][3]);
    }
    this_player()->more(explode(tmp, "\n"), "system");
    return 1;
}

void help() {
    message("help", "Syntax: <callouts>\n\n"
	    "Lists all pending callouts.\n\n"
	    "See also: events, mstatus, netstat", this_player());
}
