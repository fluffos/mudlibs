/*
 * Command                        get
 * Coder                          dazzt
 * Description                    command to take objects
 * 
 * */


#define PREV previous_object()

int main(string args)
{
	object *what, from, *inv;
	int took;
	string *itemlist, *taken;
	string items, target, obname, s;
	int i, sz;
	
    if (!args)
    {
		notify_fail("usage: get <all/item(s)> [ from <object> ]\n");
		return 0;
    }
	
// parse the container to take items from

    if (sscanf(args, "%s from %s", items, target) == 2)
	{
		from = present(target);
		if (!from)
		{
			notify_fail("No such thing here.\n");
			return 0;
		}
	}
	else
	{
		from = ENV(PREV);
		items = args;
	}
	
	if (living(from))
	{
		notify_fail("You can't take that!\n");
		return 0;
	}
		
	
	if (from->locked())
	{
		notify_fail("But " + from->short() + " is locked!\n");
		return 0;
	}
	if (from->closed())
	{
		notify_fail("But " + from->short() + " is closed!\n");
		return 0;
	}

// check for list of objects

	what = ({ });

	if (sscanf(items, "all %s", obname) == 1)
	{
		inv = all_inventory(from);
		for (i = 0, sz = sizeof(inv); i < sz; i++)
			if (inv[i]->id(obname))
				what += ({ inv[i] });
	}
	else
	{
		what = ({ });
		if (items == "all")
		{
			what = all_inventory(from);
			what -= ({ THIS });
		}
		else
		{
			itemlist = explode(items, ",");
			
			foreach (s in itemlist)
				if (present(s, from))
					what += ({ present(s, from) });
		}
	}

	if (!what || what == ({ }))
	{
		notify_fail("No such thing here.\n");
		return 0;
	}

// move objects
	
	taken = ({ });
	took = 0;
	
	for (i = 0; i < sizeof(what); i++)
	{
		if (living(what[i]))
			message("environment", "You can't get that!\n", PREV);
		else
		{
			if (ENV(what[i]) != PREV)
			{
				if ((what[i]->query_weight() + PREV->query_carried_weight()) > PREV->query_max_carry())
				{
					message("environment", "You can't carry that much!\n", PREV);
					continue;
				}
				if (what[i]->get(PREV) > 0)
				{
					if (what[i])
					{
						taken += ({ what[i]->short() });
                                                what[i]->set_is_worn(0);
						what[i]->move(PREV);
                                                PREV->check_light();
					}
					took = 1;
				}
			}
		}
	}
	
// and message it into room
	
	s = "";
	
	if (took == 0)
	{
		notify_fail("Nothing taken.\n");
		return 0;
	}

	for (i = 0, sz = sizeof(taken) - 1; i < sz; i++)
		s += taken[i] + ", ";
	s = s[0..<3];
	if (i > 0) 
		s += " and " + taken[sz];
	else
	{
		if (sizeof(taken) > 0)
			s = taken[0];
		else
			return 1;
	}
	
		
	message("environment", PREV->query_cap_name() + " takes " + s + ".\n", ENV(PREV), PREV);
	message("environment", "You take " + s + ".\n", PREV);

	return 1;
}

query_author ()
{
  return "dazzt";
}

query_help ()
{
  return "Searches players current environment, if item is in it "
       + "command will attempt to move it to players inventory. "
       + "There are few things which restrict getting items, such as "
       + "item size and item weight. Also player encumberance.";
}

query_synopsis ()
{
  return "get <item>";
}

query_see_also ()
{
  return "drop(1), give(1), put(1), i(1), eq(1)";
}

query_position ()
{
  return POS_RESTING;
}

