//shutdown.c

//Tacitus @ LPUniversity
//01-JULY-05
//Admin command

//Recoded on October 22nd, 2005 by Tacitus
//Last edited on October 22nd, 2005 by Tacitus

#include <logs.h>

int main(string arg)
{
     string status;
     int time;
     status = SHUTDOWN_D->getStatus();

     if(!adminp(previous_object())) return notify_fail("Error [shutdown]: Access denied.\n");

     if(!arg)
     {
          if(status) write("Shutdown: " + status);
          else write("There is no shutdown or reboot currently in progress.\n");
          return 1;
     }

     if(arg == "stop")
     {
          if(!status) return notify_fail("Error: There is no shutdown or reboot currently in progress.\n");
          else SHUTDOWN_D->stop();
          log_file(LOG_SHUTDOWN, capitalize(this_player()->query_name()) + " canceled the sequence (" + time + "m) on " + ctime(time()) + "\n");
          return 1;
     }

     else
     {
          if(arg == "now") time = 0;
          else time = to_int(arg);
          if(time == 0 && arg != "now" && arg != "0") return notify_fail("SYNTAX: shutdown [<stop>||<time>/now]\n");
          log_file(LOG_SHUTDOWN, capitalize(this_player()->query_name()) + " started shutdown sequence (" + time + "m) on " + ctime(time()) + "\n");
          SHUTDOWN_D->start(time, 1);
          return 1;
     }
}

string help() {
    return (HIW + " SYNTAX:" + NOR + " shutdown [<stop>||<time>/now]\n\n" +
    "This command allows you to start a shutdown of the mud. You\n"
    "can either supply the ammount of time intill you the shutdown\n"
    "is to occur or stop the current shutdown/reboot by giving the\n"
    "argument stop. You may also give the argument now to shutdown\n"
    "the mud as soon as the command is given.\n\n"
    "It is important to remember that this command will shutdown the\n"
    "the mud and will not come back up. If you wish for the mud to\n"
    "restart afterwards, then look at the reboot command.\n\n" +
    HIW + "See also: " + NOR + "reboot\n");
}
