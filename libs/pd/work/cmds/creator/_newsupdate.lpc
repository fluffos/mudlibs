//      based on /bin/user/_mudidea.c
//      update news to report updates for players to see
//      stormy
#include <std.h>
#include <security.h>
inherit DAEMON;
int cmd_newsupdate(string text);
void help();
int
cmd_newsupdate(string text)
{
        if( !text )
        {
                help();
                return 1;
        }
        seteuid(UID_LOG);
        log_file("update", "Update reported by "+capitalize( (string)this_player()->query_name())+" "+ctime(time())+"\n");
         log_file("update", "* "+text+"\n\n");
        seteuid(getuid());
        write("Update reported, thank you!\n");
        return 1;
}
void help() {
        write(
      "Syntax: <newsupdate [message]>\n\n"
      "Please use this command to report updates you have made so players can keep track.\n"
      "You do not need to report individual updates, just make a general post each day.\n"
    );
}
