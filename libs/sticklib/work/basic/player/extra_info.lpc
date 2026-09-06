// Module used for some extra info.  Included by player.c
// December 25, 1998 - Tamarindo

string spouse, rlname, location, birthday, webpage, icq;

status set_spouse(string arg)
{
    if (!arg)
    {
	spouse = 0;
	return 1;
    }

    spouse = lower_case(arg);
    return 1;
}

varargs mixed query_spouse(string arg)
{
    if (!spouse)
	spouse = 0;

    if (!arg)
	return spouse;

    if (stringp(arg))
	return (spouse == arg) ? 1 : 0;

    return 0;
}

status set_rlname(string arg)
{
    if (!arg)
    {
	rlname = 0;
	return 1;
    }

    rlname = capitalize(arg);
    return 1;
}

varargs mixed query_rlname(string arg)
{
    if (!rlname)
	rlname = 0;

    if (!arg)
	return rlname;

    if (stringp(arg))
	return (rlname == arg) ? 1 : 0;

    return 0;
}

status set_location(string arg)
{
    if (!arg)
    {
	location = 0;
	return 1;
    }

    location = capitalize(arg);
    return 1;
}

varargs mixed query_location(string arg)
{
    if (!location)
	location = 0;

    if (!arg)
	return location;

    if (stringp(arg))
	return (location == arg) ? 1 : 0;

    return 0;
}

status set_birthday(string arg)
{
    if (!arg)
    {
	birthday = 0;
	return 1;
    }

    birthday = arg;
    return 1;
}

varargs mixed query_birthday(string arg)
{
    if (!birthday)
	birthday = 0;

    if (!arg)
	return birthday;

    if (stringp(arg))
	return (birthday == arg) ? 1 : 0;

    return 0;
}

status set_webpage(string arg)
{
    if (!arg)
    {
	webpage = 0;
	return 1;
    }

    webpage = lower_case(arg);
    return 1;
}

varargs mixed query_webpage(string arg)
{
    if (!webpage)
	webpage = 0;

    if (!arg)
	return webpage;

    if (stringp(arg))
	return (webpage == arg) ? 1 : 0;

    return 0;
}

status set_icq(string arg)
{
    if (!arg)
    {
	icq = 0;
	return 1;
    }

    icq = arg;
    return 1;
}

varargs mixed query_icq(string arg)
{
    if (!icq)
	icq = 0;

    if (!arg)
	return icq;

    if (stringp(arg))
	return (icq == arg) ? 1 : 0;

    return 0;
}
