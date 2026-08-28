/*
 * File                           /mortal/command/command.c
 * Description                    Defines command aliases
 * Coder                          Dazzt
 * */


int main(string args)
{
	string cmd, cmdalias;
	int i, sz;
	mapping m_cmd;
	
	
	if (!args)
	{
		m_cmd = THIS->query("clpp_cmds");
		if (!m_cmd || m_cmd == ([ ]))
			message("standard", "You don't have any command aliases defined.\n", THIS);
		else
		{
			message("standard", "Your current command aliases are: \n", THIS);
			for (i = 0, sz = sizeof(keys(m_cmd)); i < sz; i++)
				message("standard", "'" + keys(m_cmd)[i] + "' -> '" + 
						values(m_cmd)[i] + "'\n", THIS);
			message("standard", "You have total of " + sizeof(keys(m_cmd)) + " commands out of 50.\n", THIS);
		}
		return 1;
	}
	
	if (sscanf(args, "%s %s", cmd, cmdalias) != 2)
	{
		notify_fail("usage: command <alias> <commands>\n");
		return 0;
	}
	
	if (THIS->set_clpp_cmd(cmd, cmdalias))
		message("standard", "'" + cmd + "' is now aliased to '" + cmdalias + "'\n", THIS);
	else
		message("standard", "You have exceeded your maximum number of commands (50).\n", THIS);
	
	return 1;
}

query_author ()
{
  return "dazzt";
}

query_help ()
{
  return "This command takes in two parameters 'alias name', the first "
       + "and 'alias body', the second. It assigns alias name to "
       + "alias body. This will allow you shorter typing of long "
       + "commands. In the example below it will \"tell namhas I love "
       + "you\" each time you type \"foo\".";
}

query_example ()
{
  return "command foo tell namhas I love you";
}

query_see_also ()
{
  return "alias(1), unalias(1), uncommand(1), parser(1)";
}
