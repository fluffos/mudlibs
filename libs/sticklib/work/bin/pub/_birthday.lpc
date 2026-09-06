// Tamarindo - Dec 30, 1998

string query_end(int num);

status birthday_cmd(string str)
{
    int month, day, num;
    string foo;

    if (!str)
    {
	if (!(foo = this_player()->query_birthday()))
	{
	    this_player()->tell_me("You have not set your birthday.");
	    return 1;
	}

	this_player()->tell_me("Your birthday is set as "+foo+".");
	return 1;
    }

    if (str == "-clear")
    {
	this_player()->set_birthday();
	this_player()->tell_me("Your birthday field has been cleared.");
	return 1;
    }

    if (sscanf(str, "%d/%d", month, day) < 2)
	return notify_fail("Syntax:  birthday mm/dd\n"), 0;

    if (month < 1 || month > 12 || day < 1 || day > 31)
	return notify_fail("Invalid month or day.  Try using the EARTH calendar!\n"), 0;

    switch (month)
    {
    case 1: foo = "January"; break;
    case 2: foo = "February"; if (day > 29) day = 0; break;
    case 3: foo = "March"; break;
    case 4: foo = "April"; if (day > 30) day = 0; break;
    case 5: foo = "May"; break;
    case 6: foo = "June"; if (day > 30) day = 0; break;
    case 7: foo = "July"; break;
    case 8: foo = "August"; break;
    case 9: foo = "September"; if (day > 30) day = 0; break;
    case 10: foo = "October"; break;
    case 11: foo = "November"; if (day > 30) day = 0; break;
    case 12: foo = "December"; break;
    }

    if (!day)
	return notify_fail("Invalid day.  Try using the EARTH calendar!\n"), 0;

    if (day - 30 >= 0)
	num = day - 30;
    else if (day - 20 >= 0)
	num = day - 20;
    else if (day - 10 >= 0)
	num = day - 10;
    else
	num = day;

    this_player()->set_birthday(str = foo+" "+day+query_end(num));

    this_player()->tell_me("Your birthday has been set as \""+str+"\".");

    return 1;
}

string query_end(int num)
{
    string tmp;

    switch (num)
    {
    case 1: tmp = "st"; break;
    case 2: tmp = "nd"; break;
    case 3: tmp = "rd"; break;
    default: tmp = "th"; break;
    }

    return tmp;
}
