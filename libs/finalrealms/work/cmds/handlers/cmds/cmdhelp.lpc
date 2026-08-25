// /global/cmd/cmds/cmd.c (confusing hey? :)
// Gives info on command handler, commands etc :)

#include <standard.h>
#include <cmd.h>

inherit CMD_BASE;

nosave mapping cmd_dirs, cmd_hash;
nosave string last_dir, file;

void setup()
{
  position = 0;
}

string query_usage()
{
  return "cmdhelp verb";
}

string query_short_help()
{
	return "Return help on the specified command. Note, this "+
		"particular help command [cmdhelp] only searches for "+
		"help on commands handled by a specific part of the "+
		"system. It is internally aliaseed to 'help' if help "+
		"fails.";
}

protected int cmd(string tail, object thisob)
{
  string str, usage, help;

  if(!tail || tail=="")
  {
    notify_fail("Get help on what command?\n");
    return 0;
  }

  str = (string)CMD_HANDLER->query_alias(tail);
  if(stringp(str) && str!=0 && str!="")
    tail = str;

  file = (string)CMD_HANDLER->find_cmd(tail);

  if(!file || file=="")
  {
    notify_fail("Command '"+tail+"' was not found.\n");
    return 0;
  }

	usage = (string)file->query_usage();
	help = (string)file->query_short_help();

	if(!stringp(usage) && !stringp(help))
	{
		notify_fail("No help available on "+tail+".\n");
		return 0;
	}

	if(stringp(usage))
	{
		write("Usage: "+usage+"\n\n");
	}

	if(stringp(help))
	{
		write(help+"\n\n");
	}
	return 1;
}
