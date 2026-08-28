/*
 * file                            /command/mortal/err.c 
 * description                     fixes errors from last command
 * coder                           dazzt
 * */

/* syntax:  err <typo> <corrected> */

int main(string args)
{
	string typo, corrected;
	string *last;
	string fixed;
	
	if (!args || (sscanf(args, "%s %s", typo, corrected) != 2))
	{
		notify_fail("usage: err <typo> <corrected>\n");
		return 0;
	}
	
	last = THIS->query_clh_arr();
	fixed = replace_string(last[sizeof(last) - 2], typo, corrected);

	previous_object()->force_us(fixed);
	return 1;
}

query_author ()
{
  return "dazzt";
}

query_help ()
{
  return "When you make a typo in the last line you have just entered "
       + "and want to change it all you have to do is use the err "
       + "command. It will search your last input string and find "
       + "what you have typed as <typo> and relace it with <corrected>.";
}

query_synopsis ()
{
  return "err <typo> <corrected>";
}

query_see_also ()
{
  return "history(1)";
}
