// _which
// Cmd to allow you to find where a cmd is located
// Created by Zortek@TrekVerse ported to DarkeMud by Zortek
#include <std.h>
#include <daemons.h>

inherit DAEMON ;
int help();

int cmd_which(string str) {
   string cmd, *path;
   mapping alias;
   object act_ob;
   
   if (!str || str=="") return help() ;

   // search path
   path = (string *)this_player()->query_search_path();
   if (path) {
       cmd = CMD_D->find_cmd(str, path);
       if (!cmd)
           write("No " + str + " in " + implode(path, " ") + "\n");
       else
           write(cmd + "\n");
       return 1;
   }

   return 0;
}

int help() {
	write ( @ENDHELP
Usage: which <command>

The which command will search your aliases and then your path for the
specified command.  If it's an alias, it will tell you what the command
is aliased to.  And if it's found in your path, it will tell you in
which directory the command is defined.  If the particular command
is an add_action, the "localcmd" command should be used to determine
the name of the object defining it.

NOTE: The alias search capability was removed in the
port to DarkeMud due to compatibility problems.

See also: commands, localcmd.
ENDHELP
	);

	return 1 ;
}
