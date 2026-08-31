//  Harass Command
//    Will log the output of a player to a folder.
// Modified by Seeker Jan 2005
#include <daemons.h>

#define SYNTAX "harass <on|off>\n"
#define MAX_HARASS_LENGTH 300
#include <security.h>
#define OBJHARASS "/std/obj/harass"
#define HARASSDIR  "/tmp/harass/"
mapping players;

int cmd_harass(string str) {
 object logger;
    if(str!="on" && str !="off" ) return notify_fail(SYNTAX);
    if (present("harass_logger", this_player())) logger = present("harass_logger", this_player());
    if (str=="on") {
          if (logger) return notify_fail("You currently have a open harassment log file.\nTo stop logging <stop harass>\n");
          new(OBJHARASS)->move(this_player());
          message("info", "You are now logging a harassment claim.\nLog started:"+ctime(time())+"\n", this_player());
          CHAT_D->do_chat("driver", "%^BOLD%^Harassment log opened for "+
                                                                        this_player()->query_cap_name()+" at "+ctime(time())+"%^RESET%^");
          return 1;
         } 
   if (logger) {
     message("info", "Closing your harassment claim.\nLog stopped:"+ctime(time())+"\n", this_player());
    CHAT_D->do_chat("driver", "%^BOLD%^Harassment log closed for "+
                                               this_player()->query_cap_name()+" at "+ctime(time())+"%^RESET%^");
    logger->remove();
    return 1;
 }
}

void add_harass(string p, string msg) {
    write(HARASSDIR+p, ctime(time())+" "+msg+"\n");
    seteuid(UID_LOG);
    if (file_length(HARASSDIR+p) > MAX_HARASS_LENGTH) {
    write("Harass log reached its maximum size.\n");
    this_player()->force_me("harass off");
}
    seteuid(getuid());
}   
 
void help() {
    write(SYNTAX);
    write("\nThis will log everything as a player yo
 "
      "see on your terminal screen.  Use this only to "
      "report abusive players.  Do not use this for "
      "bugs/typos/etc.  This logger will automatically "
      "shut itself down after 300 lines of input.  "
      "Please do not leave this command on.  Players "
      "who abuse this service will be severly punished.\n");
}

