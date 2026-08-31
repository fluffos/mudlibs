#include <std.h>
#include <daemons.h>
inherit DAEMON;
string result;

int cmd_which(string str) {

    if(!str || str == ""){
      message("info", "Syntax: <which [command]>", this_player());
      return 1;
     }
    if(!result=CMD_D->find_cmd(str, this_player()->query_search_path())){
      message("info", "Unable to find "+str+".", this_player());
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
