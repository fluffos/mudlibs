#include <std.h>
#include <daemons.h>
#include <security.h>

inherit DAEMON;

int cmd_elections(string str) {
  if (!archp(previous_object())) return 0;
  
    seteuid(UID_LAW);
    if(str == "start")
        VOTING_D->start_elections();
    else if(str == "end") VOTING_D->end_elections();
    else {
        write("elections [start|end]");
        seteuid(getuid());
        return 1;
    }
    seteuid(getuid());
    message("shout", "Election announcement: The elections are "+
      (str == "start" ? "begun!" : "over!"), users());
    return 1;
}

void help() {
    message("help", "Syntax: <elections [start|end]>\n\n"
      "Begins the elections or ends them.", this_player()
    );
}
