 
//	File	:  /cmds/std/_do.c
//	Creator	:  Watcher@TMI  (02/07/93)
//
//	This command allows command line parsing to use multiple
//	commands separated by the preset command separator.
 
#include <mudlib.h>
 
inherit DAEMON; 
 
#define DIVIDER	","
#define SYNTAX	"Syntax: do [cmd1" + DIVIDER + "cmd2" + DIVIDER + \
		"...]\n"
 
int cmd_do(string str) {
   string *cmds, what;
   int loop, num, count;
 
   notify_fail( SYNTAX );
 
   if(!str || str == "")  return 0;
 
   //	Remove all space from the command line
 
   str = replace_string(str, DIVIDER + " ", DIVIDER);
 
   //	Parse the command line into its individual commands
 
   cmds = explode(str, DIVIDER);
 
   //	Loop through and initiate the commands in order
 
   for(loop=0; loop<sizeof(cmds); loop++)
 
   //	If multiple single commands are requested... ie: 5 smile
 
   if(sscanf(cmds[loop], "%d %s", num, what) == 2)
   for(count=0; count<num; count++)
	previous_object()->force_me( what );
 
   //	Else do the single command portion
 
   else previous_object()->force_me( cmds[loop] );
 
return 1; }
 
string help() {

   return( SYNTAX + "\n" +
	  "This command allows you to give multiple commands at one time,\n" +
	  "separated by a \"" + DIVIDER + "\" between each command set.\n" +
	  "For example: do get sword,wield sword,kill balrog\n");
 
}
 
