// Tamarindo - Dec 30, 1998

status webpage_cmd(string str)
{
    int t;
    string foo;
    string* tmp;

    if (!str)
    {
	if (!(foo = this_player()->query_webpage()))
	{
	    this_player()->tell_me("You have not set your webpage.");
	    return 1;
	}

	this_player()->tell_me("Your webpage is set as "+foo+".");
	return 1;
    }

    if (str == "-clear")
    {
	this_player()->set_webpage();
	this_player()->tell_me("Your webpage field has been cleared.");
	return 1;
    }

    if (sizeof(str) > 50)
	return notify_fail("That name is much too long! "
	  "(max 50 chars)\n"), 0;

    if (strstr(str, " ", 0) != -1)
	return notify_fail("Please set only one webpage! (no spaces)\n"), 0;

    if (strstr(str, "http://", 0) == -1)
	str = "http://"+str;

    this_player()->set_webpage(str);

    this_player()->tell_me("Your webpage has been set as \""+str+"\".");
    return 1;
}
