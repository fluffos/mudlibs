// _which
// Tells you which directory a given command is in.
// Original author unknown, quite possibly Sulam or Buddha.
// Mobydick added help and header, 11-20-92.
// Robocoder changed search order, and updated help (93.08.28)

#include <daemons.h>
#include <mudlib.h>

inherit DAEMON ;
int help();

int cmd_which(string str) {
   string cmd, *path;
   mapping alias;
   object act_ob;
   
   if (!str || str=="") return help() ;

   // search aliases
   act_ob = previous_object();
   alias = (mapping)act_ob->query_aliases() +
         (mapping)GA_SERVER_D->query_global_aliases() +
         (mapping)GA_SERVER_D->query_global_xaliases();
   if (alias && alias[str]) {
      write(str + ":\taliased to \"" + alias[str] + "\"\n");
      return 1;
   }

   // search path
   path = explode((string)this_player()->query("PATH"), ":");
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

See also: commands, localcmd.
ENDHELP
	);

	return 1 ;
}
