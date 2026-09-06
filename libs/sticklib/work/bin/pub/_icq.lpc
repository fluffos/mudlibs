// Tamarindo - Feb 21, 1999

status icq_cmd(string str)
{
    int x, t;
    status flag;
    string foo;

    if (!str)
    {
	if (!(foo = this_player()->query_icq()))
	{
	    this_player()->tell_me("You have not set your icq number.");
	    return 1;
	}

	this_player()->tell_me("Your icq number is set as "+foo+".");
	return 1;
    }

    if (str == "-clear")
    {
	this_player()->set_icq();
	this_player()->tell_me("Your icq number has been cleared.");
	return 1;
    }

    if (sizeof(str) > 8)
	return notify_fail("That number is much too large!  "
	  "Please check again! (max 8 digits)\n"), 0;

    flag = 0;

    for (t = 0; t < sizeof(str); t++)
	if (str[t] < '0' || str[t] > '9')
	    flag = 1;

    if (flag)
	return notify_fail("Numbers only! (0-9)\n"), 0;

    this_player()->set_icq(str);
    this_player()->tell_me("Your icq number has been set as \""+str+"\".");
    return 1;
}
