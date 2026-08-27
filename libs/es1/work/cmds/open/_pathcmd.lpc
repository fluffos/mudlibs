//#pragma save_binary
// _pathcmd.c
// This is a quick hack at the moment.
// But it should work...
// -- Buddha
// Moby added help, 11-21-92. BEAT CAL!

#include <daemons.h>
#include <mudlib.h>
inherit DAEMON;

int cmd_pathcmd() {
   string *result, *path, text;
   int i, j;
   text = ""; 
   path = explode((string)previous_object()->query("PATH"), ":");
   for (i=0;i<sizeof(path);i++) { 
      result = (string *)CMD_D->list_cmds(path[i]);
      if (!result) {
         write("You have no commands in " +path[i]+ "\n");
      }
      else for(j=0;j<sizeof(result);j++) {
         text += (result[j] + " ");
      }
   }
   write(wrap(text));
   return 1;
}

int help() {
 	write ("Usage: pathcmd\n\n"+
"The pathcmd command will list every command in your path. Between the\n"+
"pathcmd command and the localcmd command, you can list everything that\n"+
"is a command for you except soul commands, which can be listed by using\n"+
"the semote command.\n") ;
	return 1 ;
}
