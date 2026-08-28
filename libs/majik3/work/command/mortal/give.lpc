/****
*  *    Command                         give
* *     Description                     Gives item to another living object
**      Coder                           Dazzt
*/


int main(string args)
{
    object obj, targobj;
    string objname, target;
    string targname;

    if (!args || sscanf(args, "%s to %s", objname, target) != 2)
    {
	notify_fail("Usage: give <something> to <someone>\n");
	return 0;
    }

    obj = present(objname, THIS);
    targobj = present(target, environment(THIS));

    if (!obj)
    {
	notify_fail("You don't have such item.\n");
	return 0;
    }
    if (!targobj)
    {
	notify_fail("There isn't any " + target + " here.\n");
	return 0;
    }
    if (!living(targobj))
    {
	notify_fail("You can't give to that!\n");
	return 0;
    }

    obj->move(targobj);

    if (interactive(targobj))
	targname = capitalize(targobj->query_name());
    else
	targname = targobj->short();

    message("environment", capitalize(THIS->query_name()) + " gives " + 
      obj->short() + " to " + capitalize(targobj->query_name()) + ".\n", 
      environment(THIS), ({ THIS, targobj }));
    message("environment", "You give " + obj->short() + " to " + 
      capitalize(targobj->query_name()) + ".\n", THIS);
    message("environment", capitalize(THIS->query_name()) + " gives " + 
      obj->short() + " to you.\n", targobj);

    return 1;
}

query_author ()
{
  return "dazzt";
}

query_synopsis ()
{
 return "give <something> to <someone>";
}

query_help ()
{
  return "Using this command you can give 'something' to 'someone'.";
}

query_example ()
{
  return "give sword to namhas";
}

query_see_also ()
{
  return "get(1), drop(1), eq(1), i(1)";
}

query_position ()
{
  return POS_RESTING;
}

