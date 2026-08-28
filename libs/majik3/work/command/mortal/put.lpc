/****
*  *    Command                                 put
* *     Description                             Put items in containers
**      Coder                                   Dazzt
*/

int main(string args)
{
    string item, target;
    object itemobj, container;

    if (!args || sscanf(args, "%s in %s", item, target) != 2)
    {
	notify_fail("Syntax: put <item> in <container>\n");
	return 0;
    }

    if (!(itemobj = present(item)))
    {
	notify_fail("No such item here.\n");
	return 0;
    }

    if (!(container = present(target)))
    {
	notify_fail("Put " + itemobj->short() + " in what?\n");
	return 0;
    }

    if (container->query_locked())
    {
	notify_fail("But " + container->short() + " is locked!\n");
	return 0;
    }

    if (container->query_closed())
    {
	notify_fail("But " + container->short() + " is closed!\n");
	return 0;
    }

    if (living(itemobj))
    {
	notify_fail("You can't do that!\n");
	return 0;
    }

    if (container->putobj(itemobj))
    {
	message("standard", "You put " + itemobj->short() + " into " + container->short() + ".\n", THIS);
	message("standard", capitalize(THIS->query_name()) + " puts " + itemobj->short() + 
	  " into " + container->short() + ".\n", environment(THIS), THIS);
    }
    else
    {
	notify_fail( itemobj->short() + " doesn't fit in " + container->short() + ".\n");
	return 0;
    }

    return 1;
}

query_author()
{
  return "dazzt";
}

query_help()
{
  return"Searches environment for possible containers and compares it to arguments."
  + " If everything is found valid it moves <item> in <container>.";
}

query_synopsis()
{
  return "put <item> in <container>";
}

query_example()
{
  return "put match in trashcan";
}

query_see_also()
{
  return "get(1), take(1), drop(1)";
}

query_position ()
{
  return POS_RESTING;
}
