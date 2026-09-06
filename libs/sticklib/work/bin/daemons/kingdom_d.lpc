// Kingdoms Daemon
// Tamarindo Jan 10, 1999

#define SAVEFILE "/data/d/kingdom_d/kingdom_d"
#define KINGDOMS ({"water", "earth", "wind", "fire"})

mapping Kingdoms;

void create()
{
    if (!restore_object(SAVEFILE))
	Kingdoms = ([ ]);
}

void save_me()
{
    save_object(SAVEFILE);
}

status set_kingdom_data(string kingdom, mixed key, mixed arg)
{
    if (!Kingdoms)
	Kingdoms = ([ ]);

    if (member(KINGDOMS, kingdom) < 0)
	return 0;

    if (stringp(key))
	key = lower_case(key);

    if (stringp(arg))
	arg = lower_case(arg);

    if (!member(Kingdoms, kingdom))
    {
	Kingdoms[kingdom] = ([ ]);
	Kingdoms[kingdom]["tax rate"] = 0;
	Kingdoms[kingdom]["revenue"] = 0;
	Kingdoms[kingdom]["donate"] = 0;
	Kingdoms[kingdom]["borrow"] = 0;
    }

    if (key == "dob")
	return 0;

    if (stringp(arg) && key == "monarch" && 
      member(({"king", "queen"}), arg) > -1)
    {
	Kingdoms[kingdom]["dob"] = time();
	Kingdoms[kingdom]["monarch"] = arg;
	Kingdoms[kingdom]["prince"] = ({ });
	Kingdoms[kingdom]["princess"] = ({ });
	Kingdoms[kingdom]["knight"] = ({ });
	Kingdoms[kingdom]["knightess"] = ({ });
	return 1;
    }

    if (intp(arg) && member(({"revenue", "donate", "borrow"}), key) > -1)
	Kingdoms[kingdom][key] += arg;
    else if (stringp(arg) &&
      member(({"prince", "princess", "knight", "knightess"}), key) > -1)
	Kingdoms[kingdom][key] += ({ arg });
    else
	Kingdoms[kingdom][key] = arg;

    save_me();

    return 1;
}

varargs status remove_kingdom_data(string kingdom, mixed key, mixed arg)
{
    if (!member(Kingdoms, kingdom))
	return 0;

    if (!key)
	return 0;

    if (stringp(key))
	key = lower_case(key);

    if (!member(Kingdoms[kingdom], key))
	return 0;

    if (key == "dob")
	return 0;

    if (member(({"revenue", "donate", "borrow"}), key) > -1)
    {
	Kingdoms[kingdom][key] = 0;
	return 1;
    }

    if (member(({"prince", "princess", "knight", "knightess"}), key) > -1)
    {
	if (!arg)
	    Kingdoms[kingdom][key] = ({ });
	else
	    Kingdoms[kingdom][key] -= ({ arg });
	return 1;
    }

    Kingdoms[kingdom][key] -= key;

    save_me();

    return 1;
}

varargs mixed query_kingdom_data(string kingdom, mixed key)
{
    if (!kingdom)
	return Kingdoms;

    if (!member(Kingdoms, Kingdoms))
	return 0;

    if (!key)
	return Kingdoms[kingdom];

    if (!member(Kingdoms[kingdom], key))
	return 0;

    return Kingdoms[kingdom][key];
}
