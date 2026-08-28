/****
****    Command                         drop
***     Description                     Drops an item to ground
**      Coder                           Dazzt
*/


#define PREV previous_object()

int main(string str)
{
    object *ob;
    int i;

    if (!str)
    {
	notify_fail("Drop what?\n");
	return 0;
    }

    if (str == "all")
    {
	ob = all_inventory(PREV);
	if(sizeof(ob)<1)
	{
	    notify_fail("You don't have anything!\n");
	    return 0;
	}
    }
    else
	ob = ({present(str,PREV)});

    if (!ob[0])
    {
	notify_fail("You don't have any " + str + ".\n");
	return 0;
    }

    for (i = 0; i < sizeof(ob); i++)
    {
	if (ob[i]->query_is_worn())
	    call_other("/command/mortal/remove", "main", ob[i]->query_name());

	message("standard", capitalize(PREV->query_name()) +
	  " drops " + ob[i]->short() + ".\n", environment(PREV), PREV);
	message("standard", "You drop " + ob[i]->short() + ".\n", PREV);

	ob[i]->move(environment(PREV));
        PREV->check_light();
    }
    return 1;
}

query_author ()
{
  return "dazzt";
}

query_help ()
{
  return "Using this command you can drop items you are carrying, "
       + "or if you are wielding/wearing the item, it will automagically "
       + "remove the item.";
}

query_synopsis ()
{
  return "drop <item>";
}

query_see_also ()
{
  return "get(1), eq(1), give(1), put(1), remove(1)";
}
  
query_position ()
{
  return POS_RESTING;
}
