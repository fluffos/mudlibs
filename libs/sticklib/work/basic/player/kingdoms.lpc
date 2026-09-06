// Module used for kingdoms.  Included by player.c
// December 25, 1998 - Tamarindo

string kingdom;

status set_kingdom(string arg)
{
    if (!arg)
    {
	kingdom = 0;
	return 1;
    }

    kingdom = lower_case(arg);
    return 1;
}

varargs mixed query_kingdom(string arg)
{
    if (!kingdom)
	kingdom = 0;

    if (!arg)
	return kingdom;

    if (stringp(arg))
	return (kingdom == arg) ? 1 : 0;

    return 0;
}
