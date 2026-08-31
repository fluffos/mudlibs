#include <std.h>
#include <daemons.h>
inherit DAEMON;
string result;

int cmd_which(string str) {

    if(!str || str == ""){
      notify_fail("Syntax: <which [command]>\n");
      return 1;
     }
    if(result=CMD_D->find_cmd(str, this_player()->query_search_path())){
      notify_fail("Unable to find "+str+".");
      return 1;
     }
    message("command", sprintf("%s : %s", str, result), this_player());
    return 1;
}

void help() {
    message ("help", "Command 'which':\n"
      "The which command will display the filename / full pathname of "
      " a command.    Usage: which <cmd>.", this_player());
}
