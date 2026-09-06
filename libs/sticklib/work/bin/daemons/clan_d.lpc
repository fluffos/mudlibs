// Clans Daemon
// Tamarindo Jan 10, 1999

#define SAVEFILE "/data/d/clan_d/clan_d"

mapping Clans;

void create()
{
    if (!restore_object(SAVEFILE))
	Clans = ([ ]);
}

void save_me()
{
    save_object(SAVEFILE);
}

status set_clan_data(string clan, mixed key, mixed arg)
{
    if (!Clans)
	Clans = ([ ]);

    if (!member(Clans, clan))
    {
	Clans[clan] = ([ ]);
	Clans[clan]["dob"] = time();
	Clans[clan]["founder"] = ({ });
	Clans[clan]["noble"] = ({ });
	Clans[clan]["tax rate"] = 0;
	Clans[clan]["revenue"] = 0;
	Clans[clan]["donate"] = 0;
	Clans[clan]["borrow"] = 0;
    }

    if (stringp(key))
	key = lower_case(key);

    if (key == "dob")
	return 0;

    if (stringp(arg) && member(({"short", "long"}), key) == -1)
	arg = lower_case(arg);

    if (intp(arg) && member(({"revenue", "donate", "borrow"}), key) > -1)
	Clans[clan][key] += arg;
    else if (stringp(arg) && member(({"founder", "noble"}), key) > -1)
	Clans[clan][key] += ({ arg });
    else
	Clans[clan][key] = arg;

    save_me();

    return 1;
}

varargs status remove_clan_data(string clan, mixed key, mixed arg)
{
    if (!member(Clans, clan))
	return 0;

    if (!key)
    {
	Clans -= ([ clan ]);

	save_me();

	return 1;
    }

    if (stringp(key))
	key = lower_case(key);

    if (!member(Clans[clan], key))
	return 0;

    if (key == "dob")
	return 0;

    if (member(({"revenue", "donate", "borrow"}), key) > -1)
    {
	Clans[clan][key] = 0;

	save_me();

	return 1;
    }

    if (member(({"founder", "noble"}), key) > -1)
    {
	if (!arg)
	    Clans[clan][key] = ({ });
	else
	    Clans[clan][key] -= ({ arg });

	save_me();

	return 1;
    }

    Clans[clan][key] -= key;

    save_me();

    return 1;
}

varargs mixed query_clan_data(string clan, mixed key)
{
    if (!clan)
	return Clans;

    if (!member(Clans, clan))
	return 0;

    if (!key)
	return Clans[clan];

    if (!member(Clans[clan], key))
	return 0;

    return Clans[clan][key];
}
