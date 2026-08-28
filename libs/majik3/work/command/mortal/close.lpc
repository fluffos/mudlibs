/****
*  *    Command                                 Close
* *     Description                             Close doors/chests etc
**      Coder                                   Dazzt/Yorkaturr
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

    if (!args)
    {
	notify_fail("Close what?\n");
	return 0;
    }

    if (!(item = present(args, THIS)))
    {
	if (!(item = find_item(args)))
	{
	    notify_fail("Close what?\n");
	    return 0;
	}
    }

    if (item == "door")
      {
        doors = ENV(THIS)->query_doors();
        if (doors[args][5] == 1)
          {
            write ("The "+doors[args][1]+" is already closed.\n");
            return 1;
          }
       else if (doors[args][5] == 2)
          {
            write ("The "+doors[args][1]+" is locked.\n");
            return 1;
          }
        else
          {
            write ("You close the "+doors[args][1]+".\n");
            tell_room (ENV(THIS), THIS->query_cap_name() + " closes the "+doors[args][1]+".\n", ({ THIS }));
            tell_area (THIS, "You hear "+doors[args][1]+" close.\n", all_inventory(ENV(THIS)));
            doors[args][5] = 1;
            ENV(THIS)->set_doors(doors);
            ENV(THIS)->remove_exit(args, doors[args][0]);
            ENV(THIS)->init(0);
            door_dest = doors[args][0]->query_doors();
            k = keys(door_dest);
            for (int i=0;i<sizeof(k);i++)
             {
               if (find_object(door_dest[k[i]][0]) == ENV(THIS)) {
                 doors[args][0]->remove_exit(k[i], door_dest[k[i]][0]);
                 doors[args][0]->init(0);
                 door_dest[k[i]][5] = 1;
                 doors[args][0]->set_doors(door_dest);
                 tell_room(doors[args][0], "The "+doors[args][1]+
                 " in "+k[i]+" closes.\n");
                 return 1;
               }
             }
          }
     }
    
    if (item->query_closable() && (!item->query_closed()))
	item->set_closed();

    message("standard", "You close " + item->query_short() + ".\n", THIS);
    message("standard", capitalize(THIS->query_name()) + " closes " + item->query_short() + ".\n",
      environment(THIS), THIS);
    return 1;
}

query_author ()
{
  return "namhas";
}

query_synopsis ()
{
  return "close <object | direction>";
}

query_example ()
{
  return "close north";
}

query_help ()
{
  return "Upon typing this you will attempt to close <object>, or if "
       + "direction is specified then you attempt to close any closeable "
       + "thing in the direction, for example a door.";
}

query_position ()
{
  return POS_STANDING;
}

