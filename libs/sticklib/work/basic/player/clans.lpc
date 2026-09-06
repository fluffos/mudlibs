// Module for handling clans.  Included by player.c
// Tamarindo Jan 9, 1998

string clan;

mapping Clan_current;
mapping Clan_history;

status set_clan(string arg)
{
    if (!arg)
    {
	clan = 0;
	return 1;
    }

    clan = lower_case(arg);
    return 1;
}

varargs mixed query_clan(string arg)
{
    if (!clan)
	clan = 0;

    if (!arg)
	return clan;

    if (stringp(arg))
	return (clan == arg) ? 1 : 0;

    return 0;
}

status set_clan_data(string field, mixed arg)
{
    if (!clan)
	return 0;

    if (!Clan_current)
	Clan_current = ([ ]);

    if (member(Clan_current, "name"))
	if (Clan_current["name"] != clan)
	{
	    if (!Clan_history)
		Clan_history = ([ ]);
	    Clan_history[Clan_current["name"]] = Clan_current;
	    Clan_current = ([ ]);
	}

    if (!sizeof(m_indices(Clan_current)))
    {
	Clan_current["name"] = clan;
	Clan_current["join"] = time();
	Clan_current["child"] = ({ });
	Clan_current["borrow"] = 0;
	Clan_current["donate"] = 0;
	return 1;
    }

    if (member(({ "donate", "borrow" }), field) != -1)
	Clan_current[field] += arg;
    else if (field == "child")
	Clan_current[field] += ({ lower_case(arg) });
    else if (field == "join")
	return 0;
    else
	Clan_current[field] = arg;

    return 1;
}

varargs mixed query_clan_data(mixed field)
{
    if (!Clan_current)
	return 0;

    if (!field)
	return Clan_current;

    if (!member(Clan_current, field))
	return 0;

    return Clan_current[field];
}
