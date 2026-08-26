/*    /secure/cmds/adm/setreboot.c
 *    from the Foundation II LPC Library
 *    a command to change the hours of the reboot interval
 *    created by Descartes of Borg 950501
 */

#include <lib.h>
#include <daemons.h>

inherit LIB_DAEMON;

mixed cmd(string args) {
    int x;

    if( !args || args == "" || !archp(previous_object()) ) return 0;
    x = to_int(args);
    if( x != (int)EVENTS_D->SetRebootInterval(x) )
      return "Resetting the reboot interval failed.";
    message("system", "Reboot interval set to " + x + " hours.", 
	    this_player());
    return 1;
}

void help() {
    message("help", "Syntax: <setreboot [interval]>\n\n"
	    "Sets up the interval at which the mud will automatically "
	    "reboot.  The interval should be specified in hours.\n\n",
	    "See also: nextreboot", this_player());
}
