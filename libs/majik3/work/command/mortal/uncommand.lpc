/*
 * File                           /mortal/command/uncommand.c
 * Description                    Removes command aliases
 * Coder                          Dazzt
 * */


int main(string args)
{
	if (!args)
	{
		notify_fail("usage: uncommand <command name>\n");
		return 0;
	}
	
	if (THIS->query("clpp_cmds")[args])
	{
		THIS->remove_clpp_cmd(args);
		message("standard", "'" + args + "' command removed.\n", THIS);
	}
	else
		message("standard", "No such command.\n", THIS);
	
	return 1;
}

query_author()
{
  return"dazzt";
}

query_help()
{
  return "Removes a command alias created with 'command' You give the <name>"
  + " of the command you want to remove as an argument.";
}

query_see_also()
{
  return "command(1), alias(1), unalias(1)";
}

query_synopsis()
{
  return "uncommand <name>";
}

query_example()
{
  return "uncommand foo";
}
query_position()
{
  return POS_RESTING;
}

