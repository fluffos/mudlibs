/*    /cmds/creator/which.c
 *    from the Foundation II Object Library
 *    gives you a list of directories in which a command may be found
 *    created by Descartes of Borg 950913
 */

#include <lib.h>
#include <daemons.h>

inherit LIB_DAEMON;

mixed cmd(string args) {
    string *dirs;
    string dir, msg;

    if( !args ) return "You want to know information on which command?";
    if( !(dirs = (string *)CMD_D->GetPaths(args)) )
      return args + ": not found.";
    msg = args + ":";
    foreach(dir in dirs) msg += "\n\t" + dir;
    message("system", msg, this_player());
    return 1;
}

void help() {
    message("help", "Syntax: <which [command]>\n\n"
	    "Gives you a listing of all directories in which a command "
	    "object may be found.\n\n"
	    "See also: help", this_player());
}
