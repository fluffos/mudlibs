 
//	File	:  /cmds/xtra/_rmlog.c
//	Creator	:  Watcher@TMI  (03/28/93)
//
//	This command allows a wizard to rm their own error log 
//	or other logs in the LOG_PATH.
 
#include <mudlib.h>

inherit DAEMON;
 
#define LOG_PATH	({ "/log/" })
#define SYNTAX		"Syntax: rmlog [log name]\n"
 
int cmd_rmlog(string str) {
   mixed *dir;
   string name;
   int loop;
 
   name = (string)this_player()->query("name");
 
   if(!str || str == "") {

	if(!directory_exists(user_path(name))) {
	notify_fail("Rmlog: You have no home directory.\n");
	return 0; }

	if(!file_exists(user_path(name) + "log")) {
	notify_fail("Rmlog: Your error log is presently empty.\n");
	return 0; }

	if(!rm(user_path(name) + "log"))
	write("Rmlog: Error log removal failed.\n");
	else write("Rmlog: Error log removed.\n");

   return 1; }
 
   for(loop=0; loop<sizeof(LOG_PATH); loop++) {

  	if(!file_exists(LOG_PATH[loop] + str))
	   continue;
 
	if((int)master()->valid_write(LOG_PATH[loop] + str,
	   geteuid(this_player()), "rm") == 0) {
	notify_fail("Rmlog: Remove permission denied.\n");
	return 0; }
 
 	if(!rm(LOG_PATH[loop] + str))
	write("Rmdir: Log file removal failed.\n");
	else write("Rmdir: " + LOG_PATH[loop] + str + " removed.\n");

	return 1; }

   write("Rmdir: No such log file found.\n");
 
return 1; }

int help() {

   write( SYNTAX + "\n" +
     "This command allows a wizard to remove their error log if no log\n" +
     "name was given.  Alternatively, it will search through the mudlib's\n" +
     "log directories for the selected file, and remove it if found.\n");
 
return 1; }
 
