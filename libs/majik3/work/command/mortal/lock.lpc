/****
*  *    Command                                 Close
* *     Description                             Close doors/chests etc
**      Coder                                   Namhas
*/

mixed find_item(string item)
{
    object *inv;
    mapping doors;
    int i;

    inv = all_inventory(THIS);

    for (i = 0; i < sizeof(inv); i++)
	if (item == inv[i]->query_name()){
	if(inv[i]->query_container())
    	 return inv[i];
	else
	     return 0;
	 }
    inv = all_inventory(environment(THIS));

    for (i = 0; i < sizeof(inv); i++)
	if (item == inv[i]->query_name()){
	if(inv[i]->query_container())
	  return inv[i];
	else
	  return 0;
	}
    doors = ENV(THIS)->query_doors();

    if (doors)
      {
        i = member_array(item, keys(doors));
        if (i>-1)
        return "door";
      }

    return 0;
}

int main(string args)
{
    mixed item;
    mapping doors;
    mapping door_dest;
    string *k;
    object o, *all;
    int found = 0;

    if (!args)
    {
	notify_fail("Lock what?\n");
	return 0;
    }

    if (!(item = present(args, THIS)))
    {
	if (!(item = find_item(args)))
	{
	    notify_fail("Lock what?\n");
	    return 0;
	}
    }

    if (item == "door")
      {
        doors = ENV(THIS)->query_doors();
        if (doors[args][5] == 0)
          {
            write ("The "+doors[args][1]+" is open.\n");
            return 1;
          }
       else if (doors[args][5] == 2)
          {
            write ("The "+doors[args][1]+" is already locked.\n");
            return 1;
          }
        else
          {
            if (doors[args][3] == 0)
              {
                write ("The "+doors[args][1]+" has no keyhole.\n");
                return 1;
              }

            all = all_inventory(THIS);

            foreach (o in all)
              if (base_name(o) == doors[args][3])
                {
                  found = 1;
                  break;
                }

            if (!found)
              {
                write ("You don't have the correct key.\n");
                return 1;
              }

            write ("You lock the "+doors[args][1]+" with "+o->short()+".\n");
            tell_room (ENV(THIS), THIS->query_cap_name() + " locks the "+doors[args][1]+" with "+o->short()+".\n", ({ THIS }));

            doors[args][5] = 2;
            ENV(THIS)->set_doors(doors);
            door_dest = doors[args][0]->query_doors();
            k = keys(door_dest);
            for (int i=0;i<sizeof(k);i++)
             {
               if (find_object(door_dest[k[i]][0]) == ENV(THIS)) {
                 door_dest[k[i]][5] = 2;
                 doors[args][0]->set_doors(door_dest);
                 tell_room(doors[args][0], "The "+doors[args][1]+
                 " in "+k[i]+" is now locked.\n");
                 return 1;
               }
             }
          }
     }
    
    if (item->query_closable() && (!item->query_closed()))
	item->set_locked();

    message("standard", "You lock " + item->query_short() + ".\n", THIS);
    message("standard", capitalize(THIS->query_name()) + " locks " + item->query_short() + ".\n",
      environment(THIS), THIS);
    return 1;
}

query_author ()
{
  return "namhas";
}

query_help ()
{
  return "You can lock items and doors using this command.";
}

query_synopsis ()
{
  return "lock <item | direction>";
}

query_see_also ()
{
  return "unlock(1), open(1), close(1)";
}

query_position ()
{
  return POS_STANDING;
}

