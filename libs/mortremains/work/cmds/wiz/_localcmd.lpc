// _commands.c (/bin/dev/command)
// dev command to find out all local commands
// author: wayfarer
// Help added by Mobydick, 11-21-92. BEAT CAL!

#include <mudlib.h>

inherit DAEMON ;

int cmd_localcmd (string arg)
{
  mixed * cmds;
  int i;
  string ob;

  ob = "";
   cmds = (mixed *)previous_object()->user_commands();
  for (i = 0; i < sizeof(cmds); i++)
    {
      if (file_name(cmds[i][2]) != ob)
	{
	  if (ob != "")
	    write ("\n");
	  ob = file_name(cmds[i][2]);
	  write ("["+ob+"]\n  ");
	}
      write (cmds[i][0]+" ");
    }

  write ("\n");

  return 1;

}

int help() {
	write ("Usage: localcmd\n\n"+
"This command will show you what commands are defined by objects in your\n"+
"inventory or environment. For commands in your path, use \"pathcmd\",\n"+
"and for soul commands use \"semote\".\n") ;
	return 1 ;
}
