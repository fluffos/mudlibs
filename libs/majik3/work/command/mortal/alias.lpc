/*
 * File                           /mortal/command/alias.c
 * Description                    Defines aliases
 * Coder                          Dazzt
 * */


int main(string args)
{
	string cmd, cmdalias;
	int i, sz;
	mapping m_alias;
	
	if (!args)
	{
		m_alias = THIS->query("clpp_aliases");
		if (!m_alias || m_alias == ([ ]))
			message("standard", "You don't have any aliases defined.\n", THIS);
		else
		{
			message("standard", "Your current aliases are: \n", THIS);
			for (i = 0, sz = sizeof(keys(m_alias)); i < sz; i++)
				message("standard", "'" + keys(m_alias)[i] + "' -> '" + 
						values(m_alias)[i] + "'\n", THIS);
			message("standard", "You have total of " + sizeof(keys(m_alias)) + " aliases out of 50.\n", THIS);
		}
		return 1;
	}
	
	if (sscanf(args, "%s %s", cmd, cmdalias) != 2)
	{
		notify_fail("usage: alias <alias_name> <alias body>\n");
		return 0;
	}

	if (THIS->set_clpp_alias(cmd, cmdalias))
		message("standard", "'" + cmd + "' is now aliased to '" + cmdalias + "'\n", THIS);
	else
		message("standard", "You have exceeded your maximum number of aliases (50).\n", THIS);
	
	return 1;
}

query_synopsis()
{
  return "alias <alias name> <alias body>";
}

query_example()
{
  return "alias n namhas";
}

query_help()
{
  return "This command will take <alias name> and turn it into whatever "
       + "is put in to <alias body>.";
}

query_see_also()
{
  return "unalias(1), command(1), uncommand(1), parser(0)";
}

query_author()
{
  return "dazzt";
}
