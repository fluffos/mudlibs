/*
// Author (??)
// Help added by Brian (1/28/92)
*/
#include <config.h>
#include <mudlib.h>
 
inherit DAEMON;

int cmd_log(string path) {
 
   seteuid(getuid(previous_object()));
 
   if( path ) path = LOG_DIR + path;
 
   else {
      path = user_path(getuid(this_player()));
      path += "log";
   }
 
   if( !path ) path = LOG_DIR + "/log";
 
   if(!file_exists(path)) {
     notify_fail("Log: " + path + " does not exist.\n");
   return 0; }
 
   write(path+":\n");
 
   if(!tail(path)) {
     notify_fail("Log: Could not read " + path + "\n");
   return 0; }
 
return 1; }

int
help() {
   write("Command: log\nSyntax: log [log | lpmud.log | other]\n"+
      "If no parameter is passed then this command will show\n"+
      "you the end of the log file in your directory.  This is\n"+
      "where errors in your objects code will appear.  If you\n"+
      "pass a filename then it will look for and tail the file\n"+
      "by that name in the /log directory.  log.log and log\n"+
      "lpmud.log contain most of the errors there.\n");
   return 1;
}
/* EOF */
