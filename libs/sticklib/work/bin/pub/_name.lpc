// Tamarindo - Dec 30, 1998

status name_cmd(string str)
{
    int t;
    string foo;
    string* tmp;

    if (!str)
    {
	if (!(foo = this_player()->query_rlname()))
	{
	    this_player()->tell_me("You have not set your real name.");
	    return 1;
	}

	this_player()->tell_me("Your name is set as "+foo+".");
	return 1;
    }

    if (str == "-clear")
    {
	this_player()->set_rlname();
	this_player()->tell_me("Your real name has been cleared.");
	return 1;
    }

    if (sizeof(str) > 25)
	return notify_fail("That name is much too long!  "
	  "Please abbreviate! (max 25 chars)\n"), 0;

    tmp = explode(str, " ");

    for (t = 0; t < sizeof(tmp); t++)
	tmp[t] = capitalize(tmp[t]);

    this_player()->set_rlname(str = implode(tmp, " "));
    this_player()->tell_me("Your real name has been set as \""+str+"\".");
    return 1;
}
