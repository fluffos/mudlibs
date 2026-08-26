// _pathcmd.c
// This is a quick hack at the moment.
// But it should work...
// -- Buddha
// Moby added help, 11-21-92. BEAT CAL!
// Rust converted to table mode 4-94

#include <daemons.h>
#include <mudlib.h>
inherit DAEMON;

int cmd_pathcmd() {
   string *result, *path, text;
   int i, j;
   text = ""; 
result = ({});
   path = explode((string)previous_object()->query("PATH"), ":");
   for (i=0;i<sizeof(path);i++)  
      result += (string *)CMD_D->list_cmds(path[i]);


  text = sprintf("%-79#s\n", implode(result,"\n"));

  this_player()->more( explode(text,"\n") );
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


