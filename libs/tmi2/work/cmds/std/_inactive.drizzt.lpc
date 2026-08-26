 
//	File	:  /cmds/std/_inactive.c
//	Created :  Watcher@TMI  (09/27/92)
//
//	Command to toggle user inactive mode.
 
#define	NAME	(string)this_player()->query("cap_name")
 
#include <mudlib.h>

inherit DAEMON ;

int cmd_inactive() {
   object inshad;

   write("You set yourself in INACTIVE mode. Hit [ENTER] to return.\n");
   say(NAME + " places " + objective((string)this_player()->query("gender")) +
       "self in INACTIVE mode.\n", this_player());
 
   this_player()->set("inactive", time());
 
   input_to("stop_inactive", 1);

return 1; }

int stop_inactive() {

   write("You return to ACTIVE status after " +
     format_time(time() - (int)this_player()->query("inactive"), 1) + ".\n");
   say(NAME + " returns to ACTIVE status.\n", this_player());
   this_player()->set("inactive", 0);
 

return 1; }
 
int help() {
	write ("Usage: inactive\n\n"+
"Puts you into inactive mode. This lets people know that you are idling.\n"+
"Hitting return takes you out of it when you are in it.\n") ;
	return 1 ;
}
 
int clean_up() {  return 1;  }		// Prevent cleanup 
 
