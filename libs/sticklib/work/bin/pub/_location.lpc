// Tamarindo - Dec 30, 1998

status location_cmd(string str)
{
    int t;
    string foo;
    string* tmp;

    if (!str)
    {
	if (!(foo = this_player()->query_location()))
	{
	    this_player()->tell_me("You have not set your location.");
	    return 1;
	}

	this_player()->tell_me("Your location is set as "+foo+".");
	return 1;
    }

    if (str == "-clear")
    {
	this_player()->set_location();
	this_player()->tell_me("Your location has been cleared.");
	return 1;
    }

    if (sizeof(str) > 20)
	return notify_fail("That location is much too long!  "
	  "Please abbreviate! (max 20 chars)\n"), 0;

    tmp = explode(str, " ");

    for (t = 0; t < sizeof(tmp); t++)
	tmp[t] = capitalize(tmp[t]);

    this_player()->set_location(str = implode(tmp, " "));
    this_player()->tell_me("Your location has been set as \""+str+"\".");
    return 1;
}
