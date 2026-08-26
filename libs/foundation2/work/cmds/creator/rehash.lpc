/*
// This command is used to update an entry in /bin/api/cmd// command tables.
*/

#include <daemons.h>
#include <lib.h>

inherit LIB_DAEMON;

int help();

int cmd(string path) {
   
   if(!path) {
      return help();
   }
    else if(path == "soul") {
        SOUL_D->recompile_soul();
        message("system", "Good show.", this_player());
        return 1;
    }
    message("info", "Rehashing: "+path, this_player());
    CMD_D->eventRehash(path);
    return 1;
}

int help() 
{
   write(
 "Usage:\nrehash <path>\n" +
 "Updates the path given's entry in the command parsing lookup tables.\n");
   return 1;
}
