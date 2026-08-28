/*
 * File                           /mortal/command/unalias.c
 * Description                    Removes argument aliases
 * Coder                          Dazzt
 * */


int main(string args)
{
	if (!args)
	{
		notify_fail("usage: unalias <alias>\n");
		return 0;
	}
	if (THIS->query("clpp_aliases")[args])
	{
		THIS->remove_clpp_alias(args);
		message("standard", "'" + args + "' alias removed.\n", THIS);
	}
	else
		message("standard", "No such alias.\n", THIS);
	
	return 1;
}
query_position()
{
  return POS_RESTING;
}

